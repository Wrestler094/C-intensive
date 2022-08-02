#include <stdio.h>

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(const int *buffer, int length);
int find_numbers(const int* buffer, int length, int number, int* numbers);

int main() {
int length, buffer[10], numbers[10];

    if (input(buffer, &length)) {
        printf("n/a\n");
        return 1;
    }

    int res = sum_numbers(buffer, length);
    int num = find_numbers(buffer,
                           length,
                           res,
                           numbers);

    if (res > 0) {
        printf("%d\n", res);
        output(numbers, num);
    }  else {
        printf("n/a\n");
        return 1;
    }

    return 0;
}

int input(int *buffer, int *length) {
    if (scanf("%d", length) != 1 || *length > 10 || *length < 1) {
        return 1;
    }

    for (int *p = buffer; p - buffer < *length; p++) {
        if (scanf("%d", p) != 1) {
            return 1;
        }
    }

    return 0;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", buffer[i]);
    }

    printf("%s", "\n");
}

int sum_numbers(const int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

int find_numbers(const int* buffer, int length, int number, int* numbers) {
    int num = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[num] = buffer[i];
            num++;
        }
    }

    return num;
}
