#include <stdio.h>

int sum(int a, int b);
int sub(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

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

    int sumRes = sum(a, b);
    int subRes = sub(a, b);
    int multiplyRes = multiply(a, b);

    if (b != 0) {
        int divideRes = divide(a, b);
        printf("%d %d %d %d\n", sumRes, subRes, multiplyRes, divideRes);
    } else {
        printf("%d %d %d %s\n", sumRes, subRes, multiplyRes, "n/a");
    }

    return 0;
}

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}
