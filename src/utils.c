#include "utils.h"
#include <stdio.h>
int bit_sum(unsigned char* buf, unsigned int buf_len)
{
    unsigned int sum = 0;
    
    for(unsigned int i = 0; i < buf_len; i++)
        for(unsigned int j = 0; j < BYTE_SIZE; j++)
            sum += 2 * ((buf[i] >> j) & 1) - 1;
    
    return sum;
}

unsigned int bit_count(unsigned char byte)
{
    const unsigned int lookup[16] = {0, 1, 1, 2, 1, 2, 2, 3,
                                     1, 2, 2, 3, 2, 3, 3, 4};
    return lookup[0x0f & byte] + lookup[byte >> 4];
}

unsigned int ones_count(unsigned char* buf, unsigned int buf_len)
{
    unsigned int sum = 0;
    for(unsigned int i = 0; i < buf_len; i++)
        sum += bit_count(buf[i]);
    return sum;
}

unsigned int run_count(unsigned char* buf, unsigned int buf_len)
{   
    unsigned int run_sum = 0;
    unsigned int previous;
    int check_boundry = 0;
    for(unsigned int i = 0; i < buf_len; i++)
    {
        if(check_boundry > 0)
            run_sum += (buf[i] & 0x01) ^ previous; 
        for(unsigned int j = 1; j < BYTE_SIZE; j++)
            run_sum += ((buf[i] >> j) & 0x01) ^ ((buf[i] >> (j-1)) & 0x01);
         previous = (buf[i] >> (BYTE_SIZE - 1)) & 0x01;
         check_boundry = 1;
    }
    return run_sum + 1;
}
