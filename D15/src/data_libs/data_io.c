#include "data_io.h"

void input_n(int *n) {
    scanf("%d", n);
}

void input(double *data, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%.2lf", data[i]);
        } else {
            printf(" %.2lf", data[i]);
        }
    }
}
