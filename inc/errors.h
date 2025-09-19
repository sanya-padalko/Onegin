#ifndef _ERRORS_H_
#define _ERRORS_H_

#include <stdio.h>

#define my_assert(comp, code_err, ret_value) if (code_error == NULL) code_error = (ERRORS*)calloc(1, sizeof(ERRORS)); if (!comp) {print_err_message(__FILE__, __FUNCTION__, __LINE__, code_err); *code_error = code_err; return ret_value;}

#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define BLUE_COLOR "\033[36"

enum ERRORS {
    NOTHING        =   0,
    FILE_ERR       =   1,
    NULLPTR        =   2,
    NAN_ERR        =   3,
    INFINITY_DIGIT =   4
};

void print_err_message(const char *file_name, const char* func_name, const int n_line,
                       const int error_code);

#endif // _ERRORS_H