#include <stdio.h>
#include <math.h>

int main() {
    float a, b;
    if (scanf("%f %f", &a, &b) != 2) {
        printf("n/a\n");
        return 1;
    }

    if (pow(a, 2) + pow(b, 2) <= 25) {
        printf("%s", "GOTCHA\n");
    } else {
        printf("%s", "MISS\n");
    }
}
