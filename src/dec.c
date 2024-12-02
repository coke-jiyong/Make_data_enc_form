#include "aes.h"
#include "dec.h"
#include "utils.h"
#define AES_KEY_LEN 32
#define AES_BLOCK_SIZE 16


static size_t remove_pkcs7_padding(unsigned char *data, size_t data_len) {
    if (data_len == 0) return 0;
    unsigned char padding_value = data[data_len - 1];
    if (padding_value > AES_BLOCK_SIZE) return data_len;
    for (int i = 1; i <= padding_value; i++) {
        if (data[data_len - i] != padding_value) return data_len;
    }
    return data_len - padding_value;
}

int dec_data(FILE * orig_file , uint8_t * key, uint8_t * enc_data, size_t len) {
    
    size_t orig_size = file_len(orig_file);
    unsigned char *orig_data = (unsigned char *)malloc(orig_size);
    if (orig_data == NULL) {
        printf("[%s: %d][%s] open %s failed.\n",__FILE__,__LINE__,__func__,"../01_001_0000000001_100_server_key.xml");
        fclose(orig_file);
        return EXIT_FAILURE;
    }

    size_t read_size = fread(orig_data, 1, orig_size, orig_file);
    if (read_size != orig_size) {
        printf("[%s: %d][%s] Read %zu bytes, expected %lu bytes\n",__FILE__,__LINE__,__func__,read_size, orig_size);
        free(orig_data);
        return EXIT_FAILURE;
    }

    
    // FILE *enc_file = open_file("./encdata", "rb");
    // if (enc_file == NULL) {
    //     free(orig_data);
    //     return EXIT_FAILURE;
    // }

    // size_t enc_size = file_len(enc_file);

    // unsigned char *enc_data = (unsigned char *)malloc(enc_size);
    // if (enc_data == NULL) {
    //     printf("[%s: %d][%s] malloc failed.",__FILE__,__LINE__,__func__);
    //     fclose(enc_file);
    //     free(orig_data);
    //     return EXIT_FAILURE;
    // }

    // read_size = fread(enc_data, 1, enc_size, enc_file);
    // if (read_size != enc_size) {
    //     printf("[%s: %d][%s] Read %zu bytes, expected %lu bytes\n",__FILE__,__LINE__,__func__,read_size, enc_size);
    //     fclose(enc_file);
    //     free(orig_data);
    //     free(enc_data);
    //     return EXIT_FAILURE;
    // }
    // fclose(enc_file);
    struct AES_ctx ctx;
    AES_init_ctx(&ctx, key);
    
    for (size_t i = 0; i < len; i += AES_BLOCK_SIZE) {
        AES_ECB_decrypt(&ctx, enc_data + i);
    }
    
    size_t decrypted_size = remove_pkcs7_padding(enc_data, len);
    
    if (decrypted_size == orig_size && memcmp(orig_data, enc_data, decrypted_size) == 0) {
        printf("Success: Decrypted data matches the original file.\n");
    } else {
        printf("Failed: Decrypted data does not match the original file.\n");
    }

    free(orig_data);


    return 0;
}