#include "../inc/errors.h"
#include "../inc/utils.h"
#include "../inc/strings.h"
#include "../inc/sorting.h"

int main() {

    // Naming

    char* file_name     =          "Onegin.txt";
    char* file_original = "Original_Onegin.txt";
    char* file_sorting  =  "Sorting_Onegin.txt";

    // Reading file

    int file_size = get_file_size(file_name);

    char* buf = (char*)calloc(file_size, sizeof(char));
    my_assert(!buf, NULLPTR);

    input_file(buf, file_name, file_size);

    int n_strings = count_strings(buf, file_size);
    
    fprintf(stderr, "\033[32m%d symbols,   %d strings\033[0m\n", file_size, n_strings);

    // Finding strings
    
    char** mas_point = (char**)calloc(n_strings + 1, sizeof(char*));
    my_assert(!mas_point, NULLPTR);

    STR* mas_str = (STR*)calloc(n_strings + 1, sizeof(STR));
    my_assert(!mas_str, NULLPTR);

    separate_strings(buf, mas_point, mas_str, file_size);

    // Sorting

    bubble_sort(mas_point, n_strings);

    qsort(mas_str, n_strings, sizeof(STR), &compar);

    // Output text

    output_file(buf, file_original, file_size);

    // Output sorting text

    FILE* file_answer = fopen(file_sorting, "wb");
    
    for (int i = 0; i < n_strings; ++i) {
        my_puts(mas_str[i].start, file_answer);
    }

    for (int i = 0; i < 15; ++i) {
        my_puts("", file_answer);
    }
    
    my_puts("---------------------------------------------------------------------------\n", file_answer);

    for (int i = 0; i < 15; ++i) {
        my_puts("", file_answer);
    }

    for (int i = 0; i < n_strings; ++i) {
        my_puts(mas_point[i], file_answer);
    }
}