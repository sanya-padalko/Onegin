#ifndef _UTILS_H_
#define _UTILS_H_

#include "errors.h"

struct STR {
    char* start = 0;
    int len = 1;
};

void input_file(char* buf, char* file_name, int file_size);

void output_file(char* buf, char* file_name, int file_size);

#endif // _UTILS_H