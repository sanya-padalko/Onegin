#include "../inc/errors.h"

const char* err_msg[] = {"Everything is OK",
                         "Working with a file went wrong",
                         "Pointer went equal NULL",
                         "Variable went equal NAN",
                         "The digit didn't become finite"};

void print_err_message(const char *file_name, const char* func_name, const int n_line,
                       const int error_code) {
    fprintf(stderr, "\033[31m%s in %s, in fuction %s, in line %d\033[0m\n", err_msg[error_code], file_name, func_name, n_line);
}