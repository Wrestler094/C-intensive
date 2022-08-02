#include <stdio.h>
#define LEN 100

int input(int *buff, int *len);

void sum(int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length);
// void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод: 
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
  int buff1[100], len1, buff2[100], len2, result[101], result_length = 0;

  input(buff1, &len1);
  input(buff2, &len2);

  sum(buff1,
      len1,
      buff2,
      len2,
      result,
      &result_length);

  return 0;
}

int input(int *buff, int *len) {
  char c;
  int index = 0;

  while (scanf("%d%c", &buff[index++], &c) == 2) {
    if (c == '\n' || c == '\0') {
      break;
    } else if (buff[index] < 0 || buff[index] > 9) {
      printf("n/a\n");
      break;
    }
  }

  *len = index;

  return 0;
}

void sum(int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length) {
  int lenCounter1 = 0;
  int lenCounter2 = 0;
  int longestArray;

  if (len1 > len2) {
    longestArray = len1;
  } else {
    longestArray = len2;
  }

  for (int i = longestArray; i > 0; i--) {
    if (len1 == len2) {
      if (buff1[len1 - 1 - *result_length] + buff2[len2 - 1 - *result_length] > 9) {
        buff1[len1 - 1 - 1 - *result_length] = buff1[len1 - 1 - 1 - *result_length] + 1;
        result[100 - *result_length] = (buff1[len1 - 1 -*result_length] + \
        buff2[len2 - 1 - *result_length]) % 10;
      } else {
        result[100 - *result_length] = buff1[len1 - 1 -*result_length] + buff2[len2 - 1 - *result_length];
      }
    } else if (len1 == longestArray) {
      if (len2 != lenCounter2) {
        result[100 - *result_length] = buff1[len1 - 1 -*result_length] + buff2[len2 - 1 - *result_length];
        lenCounter2++;
      } else {
        result[100 - *result_length] = buff1[len1 - 1 -*result_length];
      }
    } else {
      if (len1 != lenCounter1) {
        result[100 - *result_length] = buff1[len1 - 1 -*result_length] + buff2[len2 - 1 - *result_length];
        lenCounter1++;
      } else {
        result[100 - *result_length] = buff2[len2 - 1 - *result_length];
      }
    }

    *result_length = *result_length + 1;
  }

  for (int i = 101 - *result_length; i < 101; i++) {
    if (i == 100) {
      printf("%d", result[i]);
    } else {
      printf("%d ", result[i]);
    }
  }
}
