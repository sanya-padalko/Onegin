#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "errors.h"
#include "strings.h"

int pryamoy_razbor(FILE* stream) {
    char strings[6043][203];

    size_t n = 0;
    int i = 0;
    int n_strings = 0;
    int max_len = 0;
    int extra_chars = 0;

    while (my_getline((char**)strings[i++], &n, stream) != -1) {
        if (n == 1)
            --i;
        else
            ++n_strings;

        max_len = MAX(max_len, n);
        extra_chars += 203 - n;

        n = 0;
    }

    printf("%d strings, longest size is %d, extra symbols is %d\n", n_strings, max_len, extra_chars);

    return n_strings;
}

void pryamoy_check(char str1[], char str2[], int len) {
    bool fl = false;
    for (int i = 0; i < len; ++i) {

        if ((!fl) && (str1[i] != str2[i])) {
            if (str1[i] < str2[i]) {
                return;
            }
            fl = true;
        }

        if (fl) {
            char c = str1[i];
            str1[i] = str2[i];
            str2[i] = c;
        }
    }
}

bool check(char* str1, char* str2) {
    my_assert(!str1, NULLPTR);
    my_assert(!str2, NULLPTR);

    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return *str1 > *str2;
        }
        ++str1;
        ++str2;
    }
    return (*str1 != '\0' && *str2 == '\0');
}

void bubble_sort(char* strings[], int n_strings) {
    for (int i = 0; i < n_strings - 1; ++i) {
        for (int j = 0; j < (n_strings - i - 1); ++j) {
            if (check(strings[j], strings[j + 1])) {
                char* str3 = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = str3;
            }
        }
    }
}

struct Node {
    Node* nxt[123];
    bool term;
};

void clear(Node* t) {
    t->nxt[0] = 0;
}

void add(char* word, Node* root) {
    printf("%d\n", root);
    while (*word != '\0') {
        if (!root->nxt[(int)*word]) {
            root->nxt[(int)*word] = (Node*)calloc(1, sizeof(Node));
            clear(root->nxt[(int)*word]);
        }
        root = root->nxt[(int)*word];
        printf("%c %d\n", *word, (int*)root);
        ++word;
    }
    root->term = true;
}

int main() { // осталось написать Бор

    FILE* onegin = fopen("Onegin.txt", "r");
    my_assert(!onegin, NULLPTR);

    char data[2][3];
    
    char* strings[6969];

    size_t n = 0;
    int i = 0;
    int n_strings = 0;
    int max_len = 0;
    int extra_chars = 0;

    while (my_getline(&strings[i++], &n, onegin) != -1) {
        if (n == 1 || !isalpha(strings[i - 1][0]))
            --i;
        else
            ++n_strings;

        max_len = MAX(max_len, n);

        n = 0;
    }

    printf("%d strings, longest size is %d, extra symbols is %d\n", n_strings, max_len, extra_chars);

    //Node* root;

    //printf("%d\n", root->nxt[0]);

    //add("popa", root);

    bubble_sort(strings, n_strings);

    for (int i = 0; i < 25; ++i) {
        my_puts(strings[i]);
    }

    fclose(onegin);

}