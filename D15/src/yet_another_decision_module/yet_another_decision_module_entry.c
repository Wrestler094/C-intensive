#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    int n;

    input_n(&n);

    if (n < 1) {
        printf("n/a");
    } else {
        double *data;
        data = malloc(n * sizeof(double));

        input(data, n);

        if (make_decision(data, n)) {
            printf("YES");
        } else {
            printf("NO");
        }

        free(data);
    }

    return 0;
}
