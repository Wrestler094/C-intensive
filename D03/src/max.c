#include <stdio.h>

int max(int a, int b);

int main() {
    float a, b;

    if (scanf("%f %f", &a, &b) != 2) {
        printf("n/a\n");
        return 1;
    }

    int intA = a;
    int intB = b;

    if (intA != a || intB!= b) {
        printf("n/a\n");
        return 1;
    }

    printf("%d\n", max(a, b));
    return 0;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
