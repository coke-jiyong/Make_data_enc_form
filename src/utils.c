#include "utils.h"

size_t file_len(FILE* file) {
    fseek(file , 0 , SEEK_END);
    size_t file_size = ftell(file);
    fseek(file , 0 , SEEK_SET);

    return file_size;
}

FILE* open_file(const char* file_name, const char* mode) {
    FILE *file;
    file = fopen(file_name, mode);
    if (file == NULL) {
        printf("[%s: %d][%s] open %s failed.\n",__FILE__,__LINE__,__func__,file_name);
        return NULL;
    }
    return file;
}