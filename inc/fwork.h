#ifndef _FWORKING_H_
#define _FWORKING_H_

#include "errors.h"
#include "utils.h"
#include "sorting.h"
#include "strings.h"

struct File {
    char* name = (char*)calloc(100, sizeof(char));
    int file_size = 0;
    char* buf = 0;
    int n_strings = 0;
    char** mas_point = 0;
    STR* mas_str = 0;
};

void read_information(File* file_ptr, ERRORS* code_error);

void print_information(File* file_ptr, ERRORS* code_error);

void select_strings(File* file_ptr, ERRORS* code_error);

void file_sorting(File* file_ptr, ERRORS* code_error);

void print_sorting(File* file_ptr, File* sorting_file, ERRORS* code_error);

void print_original(File* file_ptr, File* sorting_file, ERRORS* code_error);

void input_data(char* buf, char* file_name, int file_size, ERRORS* code_error);

void output_data(char* buf, char* file_name, int file_size, ERRORS* code_error);

void add_data(char* buf, char* file_name, int file_size, ERRORS* code_error);

#endif // _FWORKING_H_