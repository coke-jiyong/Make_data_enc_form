#ifndef __DEC_H__
#define __DEC_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define AES_KEY_LEN 32
#define AES_BLOCK_SIZE 16


int dec_data(FILE * orig_file, uint8_t * aes_key , uint8_t * data , size_t len);
#endif