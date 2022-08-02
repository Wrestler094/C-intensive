#include <stdio.h>
#include <math.h>
#define MAX 30

int input(int *a, int *n);
int search(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[MAX];

    if (input(data, &n) == 1) {
        return 1;
    }
    int res = search(data, n);

    printf("%d", res);

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n > 30 || *n < 1) {
        printf("%s", "n/a");
        return 1;
    }

    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            printf("%s", "n/a");
            return 1;
        }
    }

    return 0;
}

int search(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        double meanRes = mean(a, n);
        double varianceRes = variance(a, n);

        if (*p % 2 == 0 &&
            *p >= meanRes &&
            *p <= meanRes + 3 * sqrt(varianceRes) &&
            *p != 0) {
            return *p;
        }
    }

    return 0;
}

double mean(int *a, int n) {
    double res = 0;

    for (int *p = a; p - a < n; p++) {
        res = res + *p;
    }

    res = res / n;

    return res;
}

double variance(int *a, int n) {
    double res = 0;
    double meanRes = mean(a, n);

    for (int *p = a; p - a < n; p++) {
        res = res + (*p - meanRes) * (*p - meanRes);
    }

    res = res / n;

    return res;
}
