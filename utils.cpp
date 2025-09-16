#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void input_file(char* buf, char* file_name, int file_size) {
    my_assert(!buf, NULLPTR);
    my_assert(!file_name, NULLPTR);

    FILE* fp = fopen(file_name, "r");
    my_assert(!fp, NULLPTR);

    my_assert(!fread(buf, sizeof(char), file_size, fp), FILE_ERR);
    
    fclose(fp);
}

void output_file(char* buf, char* file_name, int file_size) {
    my_assert(!buf, NULLPTR);
    my_assert(!file_name, NULLPTR);

    FILE* fp = fopen(file_name, "w");
    my_assert(!fp, NULLPTR);

    my_assert(!fwrite(buf, sizeof(char), file_size, fp), FILE_ERR);
    
    fclose(fp);
}