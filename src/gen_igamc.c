/*
 * gcc -o gen_igamc gen_igamc.c 3rdparty/cephes.c -lm
 */
#include <stdio.h>
#include <stdlib.h>
#include "3rdparty/cephes.h"

int main(int argc, const char *argv[])
{
    /* first input should be the block size 
     * second should be step size
     * third should be max
     * */
    if(argc != 4)
     {
        printf("Did not include the block size!\n");
        return -1;
     }
    
    int block = atoi(argv[1]);
    float a;
    float step = atof(argv[2]);
    float max = atof(argv[3]);

    if(block == 16)
        a = (16.0/2.0)/2.0;
    else if (block == 512)
        a = (512.0/6.0)/2.0;
    else if (block == 4096)
        a = (4096.0/41.0)/2.0;
    else
     {
        printf("Invalid block size!\n");
        return 0;
     }
    int count = 0;
    float i;
    printf("float IGAMC_%i[%0.0f] = \n{", block, max / step);
    for(i = 0.0; i < max; i += step)
    {
        if(count % 10 == 0)
            printf("\n");
        printf("%0.6f, ", cephes_igamc(a, i));
        count++;
    }
    printf("};\n");

    return 0; 

}
