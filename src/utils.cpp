#include "../inc/utils.h"

void next(char** ptr) {
    my_assert(!ptr, NULLPTR);
    my_assert(!(*ptr), NULLPTR);

    while (**ptr != '\n' && !isalpha(**ptr))
        ++*ptr;
}

int get_file_size(char* file_name) {
    my_assert(!file_name, NULLPTR);

    struct stat file_stat; 
    my_assert(stat(file_name, &file_stat), FILE_ERR);

    return file_stat.st_size;
}

int count_strings(char* buf, int file_size) {
    my_assert(!buf, NULLPTR);
    
    int n_strings = 0;
    for (int i = 0; i < file_size; ++i) {
        n_strings += (buf[i] == '\n');
    }
    
    return n_strings;
}

void separate_strings(char* buf, char** mas_point, STR* mas_str, int file_size) {
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

void input_file(char* buf, char* file_name, int file_size) {
    my_assert(!buf, NULLPTR);
    my_assert(!file_name, NULLPTR);

    FILE* fp = fopen(file_name, "rb");
    my_assert(!fp, NULLPTR);

    printf("%d symnols read\n", fread(buf, sizeof(char), file_size, fp));
    
    fclose(fp);
}

void output_file(char* buf, char* file_name, int file_size) {
    my_assert(!buf, NULLPTR);
    my_assert(!file_name, NULLPTR);

    FILE* fp = fopen(file_name, "wb");
    my_assert(!fp, NULLPTR);

    fprintf(stderr, "%d symbols printed\n", fwrite(buf, sizeof(char), file_size, fp));
    
    fclose(fp);
}