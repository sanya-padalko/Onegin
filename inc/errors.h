#ifndef _ERRORS_H_
#define _ERRORS_H_

#include <stdio.h>

#define my_assert(comp, code_err) if (comp) {print_err_message(__FILE__, __FUNCTION__, __LINE__, code_err);exit(0);}

enum ERRORS {
    NOTHING        =   0,
    FILE_ERR       =   1,
    NULLPTR        =   2,
    NAN_ERR        =   3,
    INFINITY_DIGIT =   4,
    CODE_ERR_NULL  =   5
};

void print_err_message(const char *file_name, const char* func_name, const int n_line,
                       const int error_code);

#endif // _ERRORS_H