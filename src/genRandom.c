#include "genRandom.h"
//free 필수
uint8_t * gen_random(void) {
    uint8_t * buf = (uint8_t*)malloc(AES_KEY_LEN);
    if(RAND_bytes(buf , AES_KEY_LEN) != 1) {
        fprintf(stderr, "Generate key failed.\n");
        free(buf);
        return NULL;
    }
    
    return buf;
    return 0;
}