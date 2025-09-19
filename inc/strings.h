#ifndef _STRINGS_H_
#define _STRINGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "errors.h"

#define MIN(a, b) (((a) < (b)) ? a : b)
#define MAX(a, b) (((a) > (b)) ? a : b)

void my_puts(const char* str, FILE* stream, ERRORS* code_error);

void print_empty_strings(int x, FILE* stream, ERRORS* code_error);

size_t my_strlen(const char* str, ERRORS* code_error);

#endif // _STRINGS_H