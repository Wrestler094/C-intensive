#include "data_stat.h"

double max(const double *data, int n) {
    double res = data[0];

    for (int i = 0; i < n; i++) {
        if (res < data[i]) {
            res = data[i];
        }
    }

    return res;
}

double min(const double *data, int n) {
    double res = data[0];

    for (int i = 0; i < n; i++) {
        if (res > data[i]) {
            res = data[i];
        }
    }

    return res;
}

double mean(const double *data, int n) {
    double res = 0;

    for (int i = 0; i < n; i++) {
        res = res + data[i];
    }

    res = res / n;

    return res;
}

double variance(double *data, int n) {
    double res = 0;
    double meanRes = mean(data, n);

    for (int i = 0; i < n; i++) {
        res = res + (data[i] - meanRes) * (data[i] - meanRes);
    }

    res = res / n;

    return res;
}
