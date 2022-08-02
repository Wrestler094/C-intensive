#ifndef SRC_DATA_LIBS_DATA_MACRO_IO_H_
#define SRC_DATA_LIBS_DATA_MACRO_IO_H_

#include <stdio.h>

#define INPUT(TYPE, FORMAT) void input(TYPE *data, int n) { \
    for (int i = 0; i < n; i++) { \
        scanf(FORMAT, &data[i]); \
    } \
} 

#define OUTPUT(TYPE, FORMAT) void output(TYPE *data, int n) { \
    for (int i = 0; i < n; i++) { \
        if (i == 0) { \
            printf(FORMAT, data[i]); \
        } else { \
            printf(" "); \
            printf(FORMAT, data[i]); \
        } \
    } \
}

#endif  // SRC_DATA_LIBS_DATA_MACRO_IO_H_
