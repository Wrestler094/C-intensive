#include <stdio.h>
#include <stdlib.h>

#include "./s21_string.h"

void s21_strlen_test(void);
void s21_strcmp_test(void);
void s21_strcpy_test(void);
void s21_strcat_test(void);

int main() {
    #ifdef STRLEN
    s21_strlen_test();
    #endif

    #ifdef STRCMP
    s21_strcmp_test();
    #endif

    #ifdef STRCPY
    s21_strcpy_test();
    #endif

    #ifdef STRCAT
    s21_strcat_test();
    #endif

    return 0;
}

void s21_strlen_test(void) {
    char *test_cases[] = {"TEST", "test", "With space", ""};
    const int results[] = {4, 4, 10, 0};

    int i = 0;
    while (test_cases[i]) {
        printf("%s\n", test_cases[i]);
        int res = s21_strlen(test_cases[i]);
        printf("%d\n", res);

        if (res == results[i]) {
            printf("SUCCESS\n\n");
        } else {
            printf("FALSE\n\n");
        }

        i++;
    }
}

void s21_strcmp_test(void) {
    char *test_cases[][2] = {{"TEST", "TEST"}, {"test1", "test"}, \
    {"With space", "With space"}, {"abc", "acd"}};
    const int results[] = {0, 1, 0, -1};

    int i = 0;
    while (test_cases[i][0]) {
        printf("%s - %s\n", test_cases[i][0], test_cases[i][1]);
        int res = s21_strcmp(test_cases[i][0], test_cases[i][1]);
        printf("%d\n", res);

        if (res == results[i]) {
            printf("SUCCESS\n\n");
        } else {
            printf("FALSE\n\n");
        }

        i++;
    }
}

void s21_strcpy_test(void) {
    char *test_cases[] = {"TEST", "test", "With space"};
    char *results[] = {"TEST", "test", "With space"};

    int i = 0;
    while (test_cases[i]) {
        int test_length = s21_strlen(test_cases[i]);
        char *test_string = (char*) malloc(test_length + 1);

        printf("%s\n", test_cases[i]);
        char *res = s21_strcpy(test_string, test_cases[i]);
        printf("%s - %s\n", res, results[i]);

        if (s21_strcmp(res, results[i]) != 0) {
            printf("FALSE\n\n");
        } else {
            printf("SUCCESS\n\n");
        }

        free(test_string);
        i++;
    }
}

void s21_strcat_test(void) {
    char *test_cases[][2] = {{"TEST", "E"}, {"test ", "s"}, {"With space", "h"}};

    int i = 0;
    while (test_cases[i][0]) {
        printf("%s - %s\n", test_cases[i][0], test_cases[i][1]);
        char *res = s21_strcat(test_cases[i][0], test_cases[i][1]);
        printf("%s - %s -%s\n", res, test_cases[i][0], test_cases[i][1]);
    }
}
