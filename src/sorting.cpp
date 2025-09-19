#include "../inc/sorting.h"

bool eq_char(char a, char b) {
    if (isalpha(a))
        a = tolower(a);
    if (isalpha(b))
        b = tolower(b);
    return (a == b);
}

int comp_char(char a, char b) {
    if (isalpha(a))
        a = tolower(a);
    if (isalpha(b))
        b = tolower(b);
    
    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    else 
        return 0;
}

int str_compare(char* str1, char* str2, ERRORS* code_error) {
    my_assert(str1, NULLPTR, 0);
    my_assert(str2, NULLPTR, 0);

    next_ptr(&str1, code_error);
    next_ptr(&str2, code_error);
    
    while (*str1 != '\n' && *str2 != '\n') {
        if (!eq_char(*str1, *str2)) {
            return comp_char(*str1, *str2);
        }
        next_ptr(&(++str1), code_error);
        next_ptr(&(++str2), code_error);
    }

    if (*str1 == '\n' && *str2 == '\n') 
        return 0;
    if (*str1 != '\n')
        return 1;
    return -1;
}

void strswap(char* &str1, char* &str2, ERRORS* code_error) {
    my_assert(str1, NULLPTR, );
    my_assert(str2, NULLPTR, );

    char* str3 = str1;
    str1 = str2;
    str2 = str3;
}

void bubble_sort(char** strings, int n_strings, ERRORS* code_error) {
    my_assert(strings, NULLPTR, );
    my_assert(*strings, NULLPTR, );

    for (int pass = 0; pass < n_strings - 1; ++pass) {
        for (int i = 0; i < (n_strings - pass - 1); ++i) {
            if (str_compare(strings[i], strings[i + 1], code_error) == 1) {
                strswap(strings[i], strings[i + 1], code_error);
            }
        }
    }
}

int reverse_compare(const void* param1, const void* param2) {
    const STR* s1 = (STR*)param1;
    const STR* s2 = (STR*)param2;

    if (s1->len <= 1) {
        if (s2->len <= 1) {
            return 0;
        }
        return -1;
    }

    if (s2->len <= 1)
        return 1;
    
    char* start1 = s1->start;
    char* start2 = s2->start;

    char* finish1 = start1 + s1->len - 2;
    char* finish2 = start2 + s2->len - 2;

    while (finish1 > start1 && finish2 > start2 && eq_char(*finish1, *finish2)) {
        --finish1;
        --finish2;

        prev_ptr(&finish1, start1);

        prev_ptr(&finish2, start2);
    }

    return comp_char(*finish1, *finish2);
}