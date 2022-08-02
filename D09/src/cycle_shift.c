#include <stdio.h>

int input(int *array, int *length, int *num);
void shift(int *array, int length, int num);

int main() {
    int length, num, array[10];

    if (input(array, &length, &num)) {
        printf("n/a\n");
    } else {
        shift(array, length, num);
    }

    return 0;
}

int input(int *array, int *length, int *num) {
    if (scanf("%d", length) != 1 || *length > 10 || *length < 1) {
        return 1;
    }

    for (int *p = array; p - array < *length; p++) {
        if (scanf("%d", p) != 1) {
            return 1;
        }
    }

    if (scanf("%d", num) != 1) {
        return 1;
    }

    return 0;
}

void shift(int *array, int length, int num) {
    int buffer[10];
    num = num % 10;

    if (num < 0) {
        num = length + num;
    }

    int counter = 0;

    for (int i = 0; i < length; i++) {
        if (i < num) {
            buffer[i] = array[i];
        }

        if (i < length - num) {
            array[i] = array[i + num];
        } else {
            array[i] = buffer[counter];
            counter++;
        }
    }

    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }

    printf("%s", "\n");
}
