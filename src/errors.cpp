#include "../inc/errors.h"

void print_err_message(const char *file_name, const char* func_name, const int n_line,
                       const int error_code) {
    switch(error_code) {
        case FILE_ERR:
            fprintf(stderr, RED_COLOR "Working with a file went wrong");
            break;
        case NULLPTR:
            fprintf(stderr, RED_COLOR "Pointer went equal NULL");
            break;
        case NAN_ERR:
            fprintf(stderr, RED_COLOR "Variable went equal NAN");
            break;
        case INFINITY_DIGIT:
            fprintf(stderr, RED_COLOR "The digit didn't become finite");
            break;
        default:
            fprintf(stderr, GREEN_COLOR "Everything is OK");
    }
    
    fprintf(stderr, " in %s, in fuction %s, in line %d\n" RESET_COLOR, file_name, func_name, n_line);
}