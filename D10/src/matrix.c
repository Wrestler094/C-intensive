#include <stdio.h>
#include <stdlib.h>

int inputMode(int *n);
int inputMatrixSize(int *columnNum, int *rowNum);
int fillMatrix(int **pointer, int columnNum, int rowNum);
int **dynamicMode1(int columnNum, int rowNum);
int **dynamicMode2(int columnNum, int rowNum);
int **dynamicMode3(int columnNum, int rowNum);
void output(int **array, int columnNum, int rowNum);

int main() {
    int mode, rowNum, columnNum;
    int staticArray[100][100];

    if (!inputMode(&mode)) {
        printf("n/a\n");
    } else if (inputMatrixSize(&rowNum, &columnNum)) {
        printf("n/a\n");
    } else {
        switch (mode) {
            case 1: {
                int *data[100];

                for (int i = 0; i < 100; i ++) {
                    data[i] = &staticArray[i][0];
                }

                fillMatrix(data, columnNum, rowNum);
                output(data, columnNum, rowNum);

                break;
            }
            case 2: {
                int **pointer = dynamicMode1(columnNum, rowNum);
                fillMatrix(pointer, columnNum, rowNum);
                output(pointer, columnNum, rowNum);

                for (int i = 0; i < rowNum; i++) {
                    free(pointer[i]);
                }

                free(pointer);

                break;
            }
            case 3: {
                int **pointer = dynamicMode2(columnNum, rowNum);
                fillMatrix(pointer, columnNum, rowNum);
                output(pointer, columnNum, rowNum);
                free(&pointer[0][0]);
                free(pointer);

                break;
            }
            case 4: {
                int **pointer = dynamicMode3(columnNum, rowNum);
                fillMatrix(pointer, columnNum, rowNum);
                output(pointer, columnNum, rowNum);
                free(pointer);

                break;
            }
            default: {
                break;
            }
        }
    }

    return 0;
}

int inputMode(int *mode) {
    int result = 0;

    if ((scanf("%d", mode) != 1) || (*mode >= 1 && *mode <= 4)) {
        result = 1;
    }

    return result;
}

int inputMatrixSize(int *columnNum, int *rowNum) {
    int result = 0;

    if (scanf("%d%d", rowNum, columnNum) != 2) {
        result = 1;
    }

    if (*rowNum < 1 || *rowNum > 100 || *columnNum < 1 || *columnNum > 100) {
        result = 1;
    }

    return result;
}

int fillMatrix(int **pointer, int columnNum, int rowNum) {
    for (int i = 0; i < columnNum; i++) {
        for (int j = 0; j < rowNum; j++) {
            scanf("%d", &pointer[i][j]);
        }
    }

    return 0;
}

int **dynamicMode1(int columnNum, int rowNum) {
    int **arr = (int **)malloc(columnNum * sizeof(int *));

    for (int i = 0; i < columnNum; i++) {
        arr[i] = (int *)malloc(rowNum * sizeof(int));
    }

    return arr;
}

int **dynamicMode2(int columnNum, int rowNum) {
    int** pointer_array = malloc(rowNum * sizeof (int*));
    int* values_array = malloc(rowNum * columnNum * sizeof(int));

    for (int i = 0; i < rowNum; i++) {
        pointer_array[i] = values_array + columnNum * i;
    }

    return pointer_array;
}

int **dynamicMode3(int columnNum, int rowNum) {
    int **singleMatrixArray = malloc(rowNum * columnNum * sizeof(int) + columnNum * sizeof(int *));
    int *pointer = (int *) (singleMatrixArray + columnNum);

    for (int i = 0; i < columnNum; i++) {
        singleMatrixArray[i] = pointer + rowNum * i;
    }

    return singleMatrixArray;
}

void output(int **array, int columnNum, int rowNum) {
    for (int i = 0; i < columnNum; i++) {
        for (int j = 0; j < rowNum; j++) {
            if (j == 0) {
                printf("%d", array[i][j]);
            } else {
                printf(" %d", array[i][j]);
            }
        }
        if (i != columnNum - 1) {
            printf("\n");
        }
    }
}
