
#include "dec.h"
#include "enc.h"
#include "genRandom.h"
#include "utils.h"
int main(void) {

    uint8_t * key = gen_random();
    if(key == NULL) {
        return 0;
    }

    size_t len;
    const char *filename = "../01_001_0000000001_100_server_key.xml";
    FILE *data_file = open_file(filename, "rb");
    if (data_file == NULL) {
        fclose(data_file);
        free(key);
        return 0;
    }

    uint8_t * enctypedData = enc_data(data_file , key , &len);
    if(enctypedData == NULL) {
        free(key);
        fclose(data_file);
        return 0;
    }


    dec_data(data_file , key, enctypedData, len);
    fclose(data_file);
    free(enctypedData);
    free(key);
    return 0;    
}