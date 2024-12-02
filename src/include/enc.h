#ifndef __ENC_H__
#define __ENC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define AES_KEY_LEN 32
#define AES_BLOCK_SIZE 16

uint8_t * enc_data(FILE * data_file , uint8_t * aes_key, size_t * len);
#endif