#ifndef UTILS_H
#define UTILS_H
#include "consts.h"
int bit_sum(unsigned char* buf, unsigned int buf_len);
unsigned int ones_count(unsigned char* buf, unsigned int buf_len);
unsigned int bit_count(unsigned char byte);
unsigned int run_count(unsigned char* buf, unsigned int buf_len);
#endif
