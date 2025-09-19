#include "../inc/errors.h"
#include "../inc/utils.h"
#include "../inc/strings.h"
#include "../inc/sorting.h"
#include "../inc/fwork.h"

int main() {

    ERRORS* code_error = (ERRORS*)calloc(1, sizeof(ERRORS));
    *code_error = NOTHING;

    File main_file;
    main_file.name = "Onegin.txt";

    File sorting_file;
    sorting_file.name =  "Sorting_Onegin.txt";
    
    read_information(&main_file, code_error);
    
    print_information(&main_file, code_error);

    select_strings(&main_file, code_error);

    file_sorting(&main_file, code_error);

    print_sorting(&main_file, &sorting_file, code_error);

    print_original(&main_file, &sorting_file, code_error);
}