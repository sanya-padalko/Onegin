#include "../inc/strings.h"

void my_puts(const char* str, FILE* stream, ERRORS* code_error) {
    my_assert(str, NULLPTR, );
    my_assert(stream, NULLPTR, );
    
    while (*str != '\n' && *str != '\0')
        fprintf(stream, "%c", *str++);

    fputc('\n', stream);
}

void print_empty_strings(int x, FILE* stream, ERRORS* code_error) {
    my_assert(stream, NULLPTR, );
    my_assert(code_error, NULLPTR, );

    for (int i = 0; i < x; ++i) {
        my_puts("", stream, code_error);
        if (i == (x / 2))
            my_puts("----------------------------------------------------------------------\n", stream, code_error);
    }
}

size_t my_strlen(const char* str, ERRORS* code_error) {
    my_assert(str, NULLPTR, 0);

    int len = 0;

    while (*str++ != '\0')
        ++len;

    return len;
}