#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

void sort(double *data, int n);
void swap(double *a, double *b);

int main() {
    double *data = NULL;
    int n;

    input_n(&n);

    data = malloc(n * sizeof(double));

    printf("LOAD DATA...\n");
    input(data, n);

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n);
    output(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);

    printf("\nFINAL DECISION:\n\t");

    if (make_decision(data, n)) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}

void sort(double *data, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;

        for (int j = i; j < n; j++) {
            if (data[j] < data[min]) {
                min = j;
            }
        }

        swap(&data[i], &data[min]);
    }
}

void swap(double *a, double *b) {
    double c = *a;
    *a = *b;
    *b = c;
}
