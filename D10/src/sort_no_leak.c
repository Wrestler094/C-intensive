#include <stdio.h>
#include <stdlib.h>

int inputNum(int *n);
int inputArray(int *data, int n);
void sort(int *data, int n);
void swap(int *a, int *b);
void output(int *data, int n);

int main() {
    int n;

    if (inputNum(&n)) {
        printf("n/a\n");
        return 1;
    }

    int *data = (int*) malloc(n * sizeof(int));

    if (inputArray(data, n)) {
        printf("n/a\n");
        return 1;
    }

    sort(data, n);
    output(data, n);

    free(data);
    return 0;
}

int inputNum(int *n) {
    if (scanf("%d", n) != 1 || *n < 1) {
        return 1;
    }

    return 0;
}

int inputArray(int *data, int n) {
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &data[i]) != 1) {
            return 1;
        }
    }

    char c;
    if (!scanf("%c", &c) && (c == '\n' || c == '\0')) {
        return 1;
    }

    return 0;
}

void sort(int *data, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;

        for (int j = i; j < n; j++) {
            if (data[j] < data[min]) {
                min = j;
            }
        }

        swap(&data[i], &data[min]);
    }
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void output(int *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d", data[i]);
        } else {
            printf(" %d", data[i]);
        }
    }

    printf("\n");
}
