#ifndef _SORTING_H_
#define _SORTING_H_

#include "errors.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int strcmp(char* str1, char* str2);

void bubble_sort(char** strings, int n_strings);

bool eq_char(char a, char b);

int compar(const void* param1, const void* param2);

#endif // _SORTING_H