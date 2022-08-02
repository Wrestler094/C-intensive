#include "./logger.h"
#include "./log_levels.h"

FILE* log_init(char *filename) {
    FILE* file;

    if ((file = fopen(filename, "a")) == NULL) {
        printf("n/a\n");
    }

    return file;
}

int logcat(FILE* log_file, char *message, log_level level) {
    char log_level[10];

    time_t t;
    struct tm *tmp;
    char MY_TIME[50];

    time(&t);
    tmp = localtime(&t);

    strftime(MY_TIME, sizeof(MY_TIME), "%X", tmp);

    switch (level) {
        case 0: {
            strcpy(log_level, "DEBUG");
            break;
        }
        case 1: {
            strcpy(log_level, "TRACE");
            break;
        }
        case 2: {
            strcpy(log_level, "INFO");
            break;
        }
        case 3: {
            strcpy(log_level, "WARNING");
            break;
        }
        case 4: {
            strcpy(log_level, "ERROR");
            break;
        }
        default: {
            break;
        }
    }

    fprintf(log_file, "%s ", log_level);
    fprintf(log_file, "%s ", message);
    fprintf(log_file, "%s", MY_TIME);

    return 0;
}

int log_close(FILE* log_file) {
    fclose(log_file);

    return 0;
}
