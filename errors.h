#ifndef _ERRORS_H_
#define _ERRORS_H_

#define my_assert(comp, code_err) if (comp) {print_err_message(__FILE__, __FUNCTION__, __LINE__, code_err);exit(0);}

enum ERRORS {
    NULLPTR        =   0,
    NAN_ERR        =   1,
    INFINITY_DIGIT =   2,
    FILE_ERR       =   3,
    NOTHING        = 100
};

void print_err_message(const char *file_name, const char* func_name, const int n_line,
                       const int error_code);

#endif // _ERRORS_H