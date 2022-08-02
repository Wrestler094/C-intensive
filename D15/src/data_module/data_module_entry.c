#include <stdlib.h>

#include "data_process.h"
#include "../data_libs/data_io.h"

int main() {
    int n;

    input_n(&n);

    if (n < 1) {
        printf("n/a");
    } else {
        double *data;
        data = malloc(n * sizeof(double));

        input(data, n);

        if (normalization(data, n)) {
            output(data, n);
        } else {
            printf("ERROR");
        }

        free(data);
    }

    return 0;
}
