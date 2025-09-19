#ifndef _SORTING_H_
#define _SORTING_H_

#include "errors.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int str_compare(char* str1, char* str2, ERRORS* code_error);

void strswap(char* &str1, char* &str2, ERRORS* code_error);

void bubble_sort(char** strings, int n_strings, ERRORS* code_error);

bool eq_char(char a, char b);

int comp_char(char a, char b);

int reverse_compare(const void* param1, const void* param2);

#endif // _SORTING_H