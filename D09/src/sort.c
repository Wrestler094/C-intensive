#include <stdio.h>

int input(int *data);
void sort(int *data);
void swap(int *a, int *b);
void output(int *data);

int main() {
    int data[10];

    if (input(data)) {
        printf("n/a\n");
        return 1;
    }

    sort(data);
    output(data);

    return 0;
}

int input(int *data) {
    for (int i = 0; i < 10; i++) {
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

void sort(int *data) {
    for (int i = 0; i < 10; i++) {
        int min = i;

        for (int j = i; j < 10; j++) {
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

void output(int *data) {
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            printf("%d", data[i]);
        } else {
            printf(" %d", data[i]);
        }
    }

    printf("\n");
}
