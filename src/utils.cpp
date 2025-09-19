#include "../inc/utils.h"

void next_ptr(char** ptr, ERRORS* code_error) {
    my_assert(ptr, NULLPTR, );
    my_assert(*ptr, NULLPTR, );

    while (**ptr != '\n' && !isalpha(**ptr))
        ++*ptr;
}

void prev_ptr(char** ptr, char* stop) {
    while (*ptr > stop && !isalpha(**ptr))
        --*ptr;
}

int get_file_size(char* file_name, ERRORS* code_error) {
    my_assert(file_name, NULLPTR, 0);

    struct stat file_stat; 
    int stat_result = stat(file_name, &file_stat);
    my_assert(!stat_result, FILE_ERR, 0);

    return file_stat.st_size;
}

int count_strings(char* buf, int file_size, ERRORS* code_error) {
    my_assert(buf, NULLPTR, 0);
    
    int n_strings = 0;
    for (int i = 0; i < file_size; ++i) {
        n_strings += (buf[i] == '\n');
    }
    
    return n_strings;
}

void separate_strings(char* buf, char** mas_point, STR* mas_str, int file_size, ERRORS* code_error) {
    my_assert(buf, NULLPTR, );
    my_assert(mas_point, NULLPTR, );
    my_assert(mas_str, NULLPTR, );

    char* ptr = buf;
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