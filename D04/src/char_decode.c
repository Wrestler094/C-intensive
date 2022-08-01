#include <stdio.h>

int code();
int decode();

int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("n/a\n");
        return 1;
    }

    int mode;
    sscanf(argv[1], "%d", &mode);

    if (mode) {
        decode();
    } else {
        code();
    }

    return 0;
}

int code() {
    char prevChar;
    char currentChar;

    prevChar = getchar();
    while ((currentChar = getchar()) != '\n') {
        if (prevChar != 32 && currentChar != 32) {
            printf("%s", "n/a\n");
            return 1;
        }

        if (prevChar != 32) {
            printf("%X", prevChar);
        }

        if (prevChar == 32) {
            printf("%c", prevChar);
        }

        prevChar = currentChar;
    }

    printf("%s", "\n");

    return 0;
}

int decode() {
    printf("%s", "decode mode\n");

    char stack1;
    char stack2;
    char stack3;

    stack1 = getchar();
    stack2 = getchar();
    while ((stack3 = getchar()) != '\n') {
        if (stack1 != 32 && stack2 != 32 && stack3 != 32) {
            printf("%s", "n/a\n");
            return 1;
        }

        printf("%c", stack3);
    }

    return 0;
}
