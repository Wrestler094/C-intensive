#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        return 1;
    }
    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n > 10 || *n < 1) {
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

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p - a == 0) {
            printf("%d", *p);
        } else {
            printf(" %d", *p);
        }
    }

    printf("\n");
}

int max(int *a, int n) {
    int res = *a;

    for (int *p = a; p - a < n; p++) {
        if (res < *p) {
            res = *p;
        }
    }

    return res;
}

int min(int *a, int n) {
    int res = *a;

    for (int *p = a; p - a < n; p++) {
        if (res > *p) {
            res = *p;
        }
    }

    return res;
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

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("%d %d %lf %lf", max_v, min_v, mean_v, variance_v);
}
