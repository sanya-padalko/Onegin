#ifndef _STRINGS_H_
#define _STRINGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "errors.h"

#define MIN(a, b) (((a) < (b)) ? a : b)
#define MAX(a, b) (((a) > (b)) ? a : b)

void my_puts(const char* str, FILE* stream);
size_t my_strlen(const char* str);

#endif // _STRINGS_H