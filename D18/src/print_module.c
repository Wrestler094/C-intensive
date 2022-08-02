#include <stdio.h>
#include <time.h>

#include "print_module.h"

char print_char(char ch) {
    return putchar(ch);
}

void print_log(char (*print)(char), char* message) {
    int i = 0;
    while (Log_prefix[i] != '\0') {
        print(Log_prefix[i]);
        i++;
    }

    print(' ');

    time_t t;
    struct tm *tmp;
    char MY_TIME[50];

    time(&t);
    tmp = localtime(&t);

    strftime(MY_TIME, sizeof(MY_TIME), "%X", tmp);

    int j = 0;
    while (MY_TIME[j] != '\0') {
        print(MY_TIME[j]);
        j++;
    }

    print(' ');

    int k = 0;
    while (message[k] != '\0') {
        print(message[k]);
        k++;
    }
}
