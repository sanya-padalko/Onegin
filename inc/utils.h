#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include "errors.h"

struct STR {
    char* start = 0;
    int len = 1;
};

void next(char** ptr);

void separate_strings(char* buf, char** mas_point, STR* mas_str, int file_size);

int get_file_size(char* file_name);

int count_strings(char* buf, int file_size);

void input_file(char* buf, char* file_name, int file_size);

void output_file(char* buf, char* file_name, int file_size);

#endif // _UTILS_H