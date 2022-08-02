#include <stdio.h>
#include <string.h>
#include <dirent.h>

void print_text(FILE *file, char *file_name);
int file_append(char *str, FILE *file, char *file_name);
void null_file(FILE *file, char *dir_name, char *file_name);
void shift_caesar(FILE *file, char *dir_name, char *file_name, int shift_num);

int main(void) {
    int is_program_laucnhed = 1;
    int mode;

    while (is_program_laucnhed) {
        FILE *file = NULL;
        char file_name[1024];

        if (scanf("%d", &mode) != 1) {
            char misstakes[1024];
            scanf("%1023s", misstakes);
            printf("n/a");
            continue;
        }

        switch (mode) {
        case 1: {
            scanf("%1023s", file_name);
            print_text(file, file_name);

            break;
        }
        case 2: {
            char str[1024];

            while ((getchar()) != '\n') {
            }

            fgets(str, 1023, stdin);

            int res = file_append(str, file, file_name);
            if (res == 0) {
                print_text(file, file_name);
            }

            break;
        }
        case 3: {
            DIR *dir;
            // struct dirent *ent;
            char dir_name[1024];
            int shift_num;

            scanf("%1023s", dir_name);
            scanf("%d", &shift_num);

            if ((dir = opendir(dir_name)) != NULL) {
                struct dirent *ent;
                while ((ent = readdir(dir)) != NULL) {
                    int length = strlen(ent->d_name);

                    if (ent->d_name[length - 2] == '.' && ent->d_name[length - 1] == 'c') {
                        shift_caesar(file, dir_name, ent->d_name, shift_num);
                    }

                    if (ent->d_name[length - 2] == '.' && ent->d_name[length - 1] == 'h') {
                        null_file(file, dir_name, ent->d_name);
                    }
                }
                closedir(dir);
            } else {
                printf("n/a");
            }

            break;
        }
        case 4:
            /* code */
            break;
        case -1:
            is_program_laucnhed = 0;
            break;
        default:
            break;
        }
    }

    return 0;
}

void print_text(FILE *file, char *file_name) {
    char file_text[1024];

    if ((file = fopen(file_name, "r")) == NULL) {
        file_name[0] = '\0';
        printf("n/a\n");
    } else {
        int i = 0;

        while (fscanf(file, "%c", &file_text[i]) != EOF) {
            i++;
        }

        if (file_text[0] == '\0') {
            printf("n/a\n");
        } else {
            for (int j = 0; j < i; j++) {
                printf("%c", file_text[j]);
            }
        }

        printf("\n");
        fclose(file);
    }
}

int file_append(char *str, FILE *file, char *file_name) {
    if ((file = fopen(file_name, "a")) == NULL) {
        printf("n/a\n");
        return 1;
    } else {
        fprintf(file, "%s", str);
        fclose(file);
    }

    return 0;
}

void null_file(FILE *file, char *dir_name, char *file_name) {
    char file_text[1024];
    file_text[0] = '\0';

    strcat(file_text, dir_name);
    strcat(file_text, file_name);

    if ((file = fopen(file_text, "w")) == NULL) {
        file_name[0] = '\0';
        printf("n/a\n");
    } else {
        fprintf(file, "%c", '\0');
        printf("\n");
        fclose(file);
    }

    file_text[0] = '\0';
}

void shift_caesar(FILE *file, char *dir_name, char *file_name, int shift_num) {
    char file_dir[1024];
    char file_text[1024];
    int i = 0;

    file_dir[0] = '\0';
    file_text[0] = '\0';

    strcat(file_dir, dir_name);
    strcat(file_dir, file_name);

    if ((file = fopen(file_dir, "r")) == NULL) {
        printf("n/a\n");
    } else {
        while (fscanf(file, "%c", &file_text[i]) != EOF) {
            i++;
        }

        fclose(file);
    }

    if ((file = fopen(file_dir, "w")) == NULL) {
        printf("n/a\n");
    } else {
        for (int j = 0; j < i; j++) {
            if (file_text[j] != '\n' && file_text[j] != '\0' && file_text[j] != ' ') {
                if (file_text[j] + shift_num > 126) {
                    fprintf(file, "%c", (file_text[j] + shift_num) % 126 + 32);
                } else if (file_text[j] + shift_num < 32) {
                    fprintf(file, "%c", 126 - (32 - (file_text[j] + shift_num)));
                } else {
                    fprintf(file, "%c", file_text[j] + shift_num);
                }
            } else {
                fprintf(file, "%c", file_text[j]);
            }
        }

        fclose(file);
    }

    file_dir[0] = '\0';
}
