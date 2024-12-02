#ifndef __UTILS_H__
#define __UTILS_H__
#include <stdio.h>

size_t file_len(FILE* file);
FILE* open_file(const char* file_name, const char* mode);
#endif