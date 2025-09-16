#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include "errors.h"
#include "strings.h"
#include "utils.h"

struct stat file_stat;

int get_size(char* file_name) {
    my_assert(!file_name, NULLPTR);

    my_assert(stat(file_name, &file_stat), FILE_ERR);

    return file_stat.st_size;
}

int count_strings(char* buf, int file_size) {
    my_assert(!buf, NULLPTR);
    
    int n_strings = 0;
    for (int i = 0; i < file_size; ++i) {
        n_strings += (buf[i] == '\n');
    }
    
    return n_strings;
}

void find_strings(char* buf, char** mas_point, STR* mas_str, int file_size) {
    char* ptr = &buf[0];
    int ind = 0;
    *mas_point++ = ptr;
    mas_str->start = ptr++;
    for (int i = 1; i < file_size; ++i) {
        if (*ptr++ == '\n') {
            mas_str->len = ptr - mas_str->start;
            ++mas_str;
            mas_str->start = *mas_point++ = ptr;
        }
    }
}

void next(char** ptr) {
    my_assert(!ptr, NULLPTR);
    my_assert(!(*ptr), NULLPTR);

    while (**ptr != '\n' && !isalpha(**ptr))
        ++*ptr;
}

bool check(char* str1, char* str2) {
    my_assert(!str1, NULLPTR);
    my_assert(!str2, NULLPTR);

    next(&str1);
    next(&str2);
    
    while (*str1 != '\n' && *str2 != '\n') {
        if (*str1 != *str2) {
            return *str1 > *str2;
        }
        next(&(++str1));
        next(&(++str2));
    }
    return (*str1 != '\n' && *str2 == '\n');
}

void bubble_sort(char* strings[], int n_strings) {
    for (int i = 0; i < n_strings - 1; ++i) {
        for (int j = 0; j < (n_strings - i - 1); ++j) {
            if (check(strings[j], strings[j + 1])) {
                char* str3 = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = str3;
            }
        }
    }
}

int compar(const void* param1, const void* param2) { // все окей, ничего не выйдет за пределы
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

    while (finish1 > start1 && finish2 > start2 && *finish1 == *finish2) {
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

int main() {

    char* file_name   = "Onegin.txt";

    int file_size = get_size(file_name);

    char buf[file_size];

    input_file(buf, file_name, file_size);

    int n_strings = count_strings(buf, file_size); // неправильное количество строк

    char* ps[n_strings];
    STR mas_str[n_strings];

    find_strings(buf, ps, mas_str, file_size);

    bubble_sort(ps, n_strings);

    qsort(mas_str, n_strings, sizeof(STR), &compar);

    for (int i = 0; i < 25; ++i)
        my_puts(mas_str[i].start);

    //output_file(buf, file_answer, file_size); // в конце мусор какой-то из-за неверного количества строк

    // вывод оставшихся двух файлов
}