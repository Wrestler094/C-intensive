#include <stdio.h>
#include <math.h>

int calc(int a);
int isDivider(int a, int i);
int isPrimeNumber(int i);
int getPositiveInt(int num);

int main() {
    int a;
    if ((scanf("%d", &a) != 1) || a == 0 || a == 1 || a == -1) {
        printf("%s", "n/a\n");
        return 1;
    }

    a = getPositiveInt(a);

    int res = calc(a);
    printf("%d\n", res);

    return 0;
}

int calc(int a) {
    for (int i = a ; i > 0; i--) {
        if (isDivider(a, i) == 1) {
            if (isPrimeNumber(i) == 1) {
                return i;
            }
        }
    }

    return 0;
}

int isDivider(int a, int i) {
    int b = a;

    while (b > 0) {
        b = b - i;
    }

    if (b == 0) {
        return 1;
    } else {
        return 0;
    }
}

int isPrimeNumber(int a) {
    for (int i = a - 1; i > 0; i--) {
        if (isDivider(a, i) == 1 && i > 1) {
            return 0;
        } else if (isDivider(a, i) == 1 && i == 1) {
            return 1;
        } else {
            continue;
        }
    }

    return 0;
}

int getPositiveInt(int num) {
    num = sqrt(num * num);

    return num;
}
