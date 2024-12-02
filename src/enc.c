#include "aes.h"
#include "enc.h"
#include "utils.h"

#define AES_KEY_LEN 32
#define AES_BLOCK_SIZE 16


static void pkcs7_padding(unsigned char *data, size_t *data_len) {
    size_t padding_len = AES_BLOCK_SIZE - (*data_len % AES_BLOCK_SIZE);
    for (size_t i = 0; i < padding_len; i++) {
        data[*data_len + i] = (unsigned char)padding_len;
    }
    *data_len += padding_len;
}

//return값 free 필수
uint8_t * enc_data(FILE* orig_file , uint8_t * key , size_t * len) {
    
    unsigned char byte; 
    size_t file_size = file_len(orig_file);
    size_t padded_size = file_size + AES_BLOCK_SIZE; // 최대 15 패딩 필요.
    uint8_t * bytes = (unsigned char *)malloc(padded_size);
    if (bytes == NULL) {
        printf("[%s: %d][%s] malloc failed.",__FILE__,__LINE__,__func__);
        fclose(orig_file);
        return NULL;
    }

    size_t cnt = fread(bytes, sizeof(unsigned char), file_size, orig_file);
    if (cnt != file_size) {
        printf("[%s: %d][%s] Read %zu bytes, expected %lu bytes\n",__FILE__,__LINE__,__func__,cnt, file_size);
        free(bytes);
        return NULL;
    }

    pkcs7_padding(bytes, &cnt);


    struct AES_ctx ctx;
    AES_init_ctx(&ctx, key);
    for (size_t i = 0; i < cnt; i += AES_BLOCK_SIZE) {
        AES_ECB_encrypt(&ctx, bytes + i);
    }
    *len = cnt;
    
    return bytes;
    // FILE* enc_data = open_file("./encdata", "wb");
    // if(enc_data == NULL) {
    //     free(bytes);
    //     return EXIT_FAILURE;
    // }
    
    // size_t write_len = fwrite(bytes, sizeof(uint8_t), cnt , enc_data);

    // if(write_len != cnt) {
    //     printf("[%s: %d][%s] Read %zu bytes, expected %lu bytes\n",__FILE__,__LINE__,__func__,write_len , cnt);
    //     fclose(enc_data);
    //     free(bytes);
    //     return EXIT_FAILURE;
    // }
    
    // fclose(enc_data);
    // free(bytes);
    
    //return 0;
}

