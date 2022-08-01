#include <stdio.h>

int get(int num);

int main() {
    int num;

    if (scanf("%d", &num) != 1 || num <= 0) {
        printf("%s", "n/a\n");
        return 1;
    }

    printf("%d\n", get(num));

    return 0;
}

int get(int num) {
    if (num < 3) {
        return 1;
    }

    return get(num - 1) + get(num - 2);
}
