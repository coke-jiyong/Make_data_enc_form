#ifndef __GENRANDOM_H__
#define __GENRANDOM_H__

#include <openssl/rand.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define AES_KEY_LEN 32
uint8_t * gen_random(void);
#endif