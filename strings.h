#ifndef _STRINGS_H_
#define _STRINGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "errors.h"

#define MIN(a, b) (((a) < (b)) ? a : b)
#define MAX(a, b) (((a) > (b)) ? a : b)

const int NULL_code = 48;
const int A_code = 65;
const int a_code = 97;

void my_puts(const char* str);
const char* my_strchr(const char* str, int c);
size_t my_strlen(const char* str);
char* my_strcpy(char* dest, const char* src);
char* my_strncpy(char* dest, const char* src, size_t n);
char* my_strcat(char* dest, const char* src);
char* my_strncat(char* dest, const char* src, size_t n);
int my_atoi(const char* nptr);
char* my_fgets(char* s, int size, FILE* stream);
char* my_strdup(const char* s);
size_t my_getline(char** lineptr, size_t* n, FILE* stream);

#endif // _STRINGS_H