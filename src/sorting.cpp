#include "../inc/sorting.h"

int strcmp(char* str1, char* str2) {
    my_assert(!str1, NULLPTR);
    my_assert(!str2, NULLPTR);

    next(&str1);
    next(&str2);
    
    while (*str1 != '\n' && *str2 != '\n') {
        if (*str1 != *str2) {
            if (*str1 > *str2) 
                return 1;
            else
                return -1;
        }
        next(&(++str1));
        next(&(++str2));
    }

    if (*str1 == '\n' && *str2 == '\n') 
        return 0;
    if (*str1 != '\n')
        return 1;
    return -1;
}

void bubble_sort(char** strings, int n_strings) {
    for (int i = 0; i < n_strings - 1; ++i) {
        for (int j = 0; j < (n_strings - i - 1); ++j) {
            if (strcmp(strings[j], strings[j + 1]) == 1) {
                char* str3 = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = str3;
            }
        }
    }
}

bool eq_char(char a, char b) {
    if (isalpha(a))
        a = tolower(a);
    if (isalpha(b))
        b = tolower(b);
    return (a == b);
}

int compar(const void* param1, const void* param2) {
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

        while (finish1 > start1 && !isalpha(*finish1))
            --finish1;

        while (finish2 > start2 && !isalpha(*finish2))
            --finish2;
    }

    if (*finish1 < *finish2) 
        return -1;
    else if (*finish1 > *finish2)
        return 1;
    else
        return 0;
}