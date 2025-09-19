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

void next_ptr(char** ptr, ERRORS* code_error);

void prev_ptr(char** ptr, char* stop);

int get_file_size(char* file_name, ERRORS* code_error);

int count_strings(char* buf, int file_size, ERRORS* code_error);

void separate_strings(char* buf, char** mas_point, STR* mas_str, int file_size, ERRORS* code_error);

#endif // _UTILS_H