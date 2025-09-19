#include "../inc/fwork.h"

void read_information(File* file_ptr, ERRORS* code_error) {
    my_assert(file_ptr, NULLPTR, );

    file_ptr->file_size = get_file_size(file_ptr->name, code_error);

    file_ptr->buf = (char*)calloc(file_ptr->file_size, sizeof(char));
    my_assert(file_ptr->buf, NULLPTR, );

    input_data(file_ptr->buf, file_ptr->name, file_ptr->file_size, code_error);

    file_ptr->n_strings = count_strings(file_ptr->buf, file_ptr->file_size, code_error);
}

void print_information(File* file_ptr, ERRORS* code_error) {
    my_assert(file_ptr, NULLPTR, );

    fprintf(stderr, GREEN_COLOR "%d symbols,   %d strings\n" RESET_COLOR, file_ptr->file_size, file_ptr->n_strings);

}

void select_strings(File* file_ptr, ERRORS* code_error) {
    my_assert(file_ptr, NULLPTR, );

    file_ptr->mas_point = (char**)calloc(file_ptr->n_strings + 1, sizeof(char*));
    my_assert(file_ptr->mas_point, NULLPTR, );

    file_ptr->mas_str = (STR*)calloc(file_ptr->n_strings + 1, sizeof(STR));
    my_assert(file_ptr->mas_str, NULLPTR, );

    separate_strings(file_ptr->buf, file_ptr->mas_point, file_ptr->mas_str, file_ptr->file_size, code_error);
}

void file_sorting(File* file_ptr, ERRORS* code_error) {
    my_assert(file_ptr, NULLPTR, );

    bubble_sort(file_ptr->mas_point, file_ptr->n_strings, code_error);

    qsort(file_ptr->mas_str, file_ptr->n_strings, sizeof(STR), &reverse_compare);
}

void print_sorting(File* file_ptr, File* sorting_file, ERRORS* code_error) {
    my_assert(file_ptr, NULLPTR, );

    FILE* file_answer = fopen(sorting_file->name, "wb");
    my_assert(file_answer, FILE_ERR, );

    for (int i = 0; i < file_ptr->n_strings; ++i) {
        my_puts(file_ptr->mas_point[i], file_answer, code_error);
    }

    print_empty_strings(31, file_answer, code_error);

    for (int i = 0; i < file_ptr->n_strings; ++i) {
        my_puts(file_ptr->mas_str[i].start, file_answer, code_error);
    }

    print_empty_strings(31, file_answer, code_error);

    int fclose_result = fclose(file_answer);
    my_assert(!fclose_result, FILE_ERR, );
}

void print_original(File* file_ptr, File* sorting_file, ERRORS* code_error) {
    my_assert(file_ptr, NULLPTR, );

    add_data(file_ptr->buf, sorting_file->name, file_ptr->file_size, code_error);
}

void input_data(char* buf, char* file_name, int file_size, ERRORS* code_error) {
    my_assert(buf, NULLPTR, );
    my_assert(file_name, NULLPTR, );

    FILE* fp = fopen(file_name, "rb");
    my_assert(fp, FILE_ERR, );

    int read_symbols = fread(buf, sizeof(char), file_size, fp);
    fprintf(stderr, GREEN_COLOR "%d symnols read\n" RESET_COLOR, read_symbols);
    my_assert(read_symbols == file_size, FILE_ERR, );

    int fclose_result = fclose(fp);
    my_assert(!fclose_result, FILE_ERR, );
}

void output_data(char* buf, char* file_name, int file_size, ERRORS* code_error) {
    my_assert(buf, NULLPTR, );
    my_assert(file_name, NULLPTR, );

    FILE* fp = fopen(file_name, "wb");
    my_assert(fp, FILE_ERR, );

    int printed_symbols = fwrite(buf, sizeof(char), file_size, fp);
    fprintf(stderr, GREEN_COLOR "%d symbols printed\n" RESET_COLOR, printed_symbols);
    my_assert(printed_symbols == file_size, FILE_ERR, );
    
    int fclose_result = fclose(fp);
    my_assert(!fclose_result, FILE_ERR, );
}

void add_data(char* buf, char* file_name, int file_size, ERRORS* code_error) {
    my_assert(buf, NULLPTR, );
    my_assert(file_name, NULLPTR, );

    FILE* fp = fopen(file_name, "ab");
    my_assert(fp, FILE_ERR, );

    int printed_symbols = fwrite(buf, sizeof(char), file_size, fp);
    fprintf(stderr, GREEN_COLOR "%d symbols printed\n" RESET_COLOR, printed_symbols);
    my_assert(printed_symbols == file_size, FILE_ERR, );
    
    int fclose_result = fclose(fp);
    my_assert(!fclose_result, FILE_ERR, );
}