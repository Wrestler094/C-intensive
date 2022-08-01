#include <stdio.h>
#include <math.h>

int main() {
    float x, y;
    if (scanf("%f", &x) != 1) {
        printf("n/a\n");
        return 1;
    }

    y = 7 * powf(10.0, -3.0) * powf(x, 4.0) + ((22.8 * powf(x, (1.0 / 3.0)) - 1 * powf(10.0, 3.0)) * \
    x + 3.0) / (x * x / 2.0) - x * powf((10.0 + x), (2.0 / x)) - 1.01;

    printf("%.1f\n", y);
    return 0;
}
