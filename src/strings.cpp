#include "../inc/strings.h"

void my_puts(const char* str, FILE* stream) {
    my_assert(!str, NULLPTR);
    my_assert(!stream, NULLPTR);
    
    while (*str != '\n' && *str != '\0')
        fprintf(stream, "%c", *str++);

    fputc('\n', stream);
}

size_t my_strlen(const char* str) {
    my_assert(!str, NULLPTR);

    int len = 0;

    while (*str++ != '\0')
        ++len;

    return len;
}