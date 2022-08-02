#include <stdio.h>
#include <stdlib.h>

#include "./s21_string.h"

int s21_strlen(const char *str) {
    int i = 0, res = 0;

    while (str[i] != '\0') {
        res++;
        i++;
    }

    return res;
}

int s21_strcmp(char *str1, char *str2) {
    int i = 0, res = 0;

    if (s21_strlen(str1) > s21_strlen(str2)) {
        res = 1;
    } else if (s21_strlen(str1) < s21_strlen(str2)) {
        res = -1;
    } else {
        while (str1[i] != '\0' || str2[i] != '\0') {
            if (str1[i] > str2[i]) {
                res = 1;
                break;
            } else if (str1[i] < str2[i]) {
                res = -1;
                break;
            } else {
                i++;
            }
        }
    }

    return res;
}

char *s21_strcpy(char *str1, char *str2) {
    char *addres = str1;

    while (*str2 != '\0') {
        *str1++ = *str2++;
    }

    return addres;
}

char *s21_strcat(char *str1, char *str2) {
    int str1_length = s21_strlen(str1);
    int str2_length = s21_strlen(str2);

    for (int i = 0; i <= str2_length; i++) {
        str1[str1_length + i] = str2[i];
    }

    return str1;
}

// char *s21_strchr(char *str, int ch) {
//     int length = s21_strlen(str);
//     int index = -1;

//     for (int i = 0; i < length || index < -1; i++) {
//         if (str[i] == ch) {
//             index = i;
//         }
//     }

//     return &str[index];
// }
