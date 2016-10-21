/*
 * Run through examples, calculate monobit freq, block freq,
 * runs, longest runs of ones. Produce a file that contains
 * the pvals and times for each pass. */

#include <stdio.h>
#include <stdlib.h>
#include "rand_tests.h"
#include "utils.h"
#include <sys/time.h>
//set this to true if we want to save the latencies
#define SAVE_TIME 0

int main(int argc, char *argv[])
{
    //get the file name from args, see if we can open the file
    if(argc == 4)
    {
        FILE *file = fopen(argv[1], "r");
        if(file == 0)
        {
            perror("Failied to open file, idiot!\n");
            return -1;
        }
        
        //grab the first 128 bits / 16 bytes from the file
        unsigned int block_size_freq;
        unsigned int buf_size = atoi(argv[3]);
        unsigned char *buf = (unsigned char *) malloc(buf_size);
        //varify that the buffer smaller than the file
        fread(buf, buf_size, 1, file);
        
        //calculate the block freq size
        if(buf_size < 256)
            block_size_freq = 2;
        else if (buf_size >= 256)
            block_size_freq = (int) (buf_size * 0.01) + 1;
        else
            goto quit;
        //printf("buf_size=%i, block_size_freq=%i\n", buf_size, block_size_freq);

        //for each testing method, grab the pvals and time
        struct timeval stop, start;

        gettimeofday(&start, NULL);
        float mb = freq_monobit(buf, buf_size);
        gettimeofday(&stop, NULL);
        unsigned int mb_time = stop.tv_usec - start.tv_usec;
        
        gettimeofday(&start, NULL);
        float fb = freq_block(buf, buf_size, block_size_freq);
        gettimeofday(&stop, NULL);
        unsigned int fb_time = stop.tv_usec - start.tv_usec;
        
        gettimeofday(&start, NULL);
        float rs = runs(buf, buf_size);
        gettimeofday(&stop, NULL);
        unsigned int rs_time = stop.tv_usec - start.tv_usec;
        
        gettimeofday(&start, NULL);
        float rbs = runs_one_block(buf, buf_size, SMALL_BLOCK);
        gettimeofday(&stop, NULL);
        unsigned int rbs_time = stop.tv_usec - start.tv_usec;
        
        /*
         * print information as a row... args should state if it;s 
         * benign class = 0, or random class = 1
         */
        if(SAVE_TIME)
            printf("%s\t%s\t%f\t%i\t%f\t%i\t%f\t%i\t%f\t%i\n",
              argv[1], argv[2], mb, mb_time, fb, fb_time, 
              rs, rs_time, rbs, rbs_time);
        else
            printf("%s\t%f\t%f\t%f\t%f\n", argv[2], mb, fb, rs, rbs);
    
        quit:
        free(buf);
        fclose(file);
    }
    else
    {
        perror("Usage: ./min_bit filename <class: 0 | 1 >\nExample: ./gen_features test.txt 0\n");
        return -1;
    }
    
    
    return 0;
}
