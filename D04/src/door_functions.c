#include <stdio.h>
#include <math.h>

double agnesi(double num);
double bernulli(double num);
double hyper(double num);

int main(void) {
    double num = -M_PI;
    double step = M_PI / 20.5;

    for (int i = 0; i < 42; i++) {
        printf("%.7lf | %.7lf | ", num, agnesi(num));

        double bernulliRes = bernulli(num);
        if (isnan(bernulliRes)) {
            printf("%s | ", "—");
        } else {
            printf("%.7lf |", bernulliRes);
        }

        printf("%.7lf\n", hyper(num));

        num = num + step;
    }

    return 0;
}

double agnesi(double num) {
    double res = 1 / (1 + num * num);

    return res;
}

double bernulli(double num) {
    double res = sqrt(sqrt(1 + 4 * num * num) - num * num - 1);

    return res;
}

double hyper(double num) {
    double res = 1 / (num * num);

    return res;
}
