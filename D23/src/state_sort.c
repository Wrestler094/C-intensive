#include <stdio.h>
#include <string.h>

struct date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
};

void print_file(FILE *file, char *file_name);
int sort_file(FILE *file, char *file_name);
int add_entry(FILE *file, char *file_name);

int get_records_count_in_file(FILE *pfile);
int get_file_size_in_bytes(FILE *pfile);
struct date read_record_from_file(FILE *pfile, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
void write_record_in_file(FILE *pfile, const struct date *record_to_write, int index);

int main(void) {
    FILE *file = NULL;

    char file_name[1024];
    scanf("%1023s", file_name);

    int mode;
    scanf("%d", &mode);

    while ((getchar()) != '\n') {
    }

    switch (mode) {
        case 0: {
            print_file(file, file_name);

            break;
        }
        case 1: {
            int is_succeed = sort_file(file, file_name);

            if (is_succeed == 0) {
                print_file(file, file_name);
            }

            break;
        }
        case 2: {
            int is_adding_succeed;
            int is_sort_succeed;

            is_adding_succeed = add_entry(file, file_name);

            if (is_adding_succeed == 0) {
                is_sort_succeed = sort_file(file, file_name);
            }

            if (is_adding_succeed == 0 && is_sort_succeed == 0) {
                print_file(file, file_name);
            }

            break;
        }
        default: {
            break;
        }
    }

    return 0;
}

void print_file(FILE *file, char *file_name) {
    if ((file = fopen(file_name, "rb")) == NULL) {
        printf("n/a");
    } else {
        struct date entry_date;
        int entry_num = get_records_count_in_file(file);

        for (int i = 0; i < entry_num; i++) {
            entry_date = read_record_from_file(file, i);

            printf("%d %d %d %d %d %d %d %d\n", entry_date.year, entry_date.month, entry_date.day, \
            entry_date.hour, entry_date.minute, entry_date.second, entry_date.status, entry_date.code);
        }

        fclose(file);
    }
}

int sort_file(FILE *file, char *file_name) {
    if ((file = fopen(file_name, "rb+")) == NULL) {
        printf("n/a");
        return 1;
    } else {
        int entry_num = get_records_count_in_file(file);

        for (int i = 0; i < entry_num; i++) {
            int min = i;

            for (int j = i; j < entry_num; j++) {
                char str_min[100];
                char str_j[100];

                struct date entry_min = read_record_from_file(file, min);
                struct date entry_j = read_record_from_file(file, j);

                sprintf(str_min, "%04d %02d %02d %02d %02d %02d %01d %03d", entry_min.year, entry_min.month,
                entry_min.day, entry_min.hour, entry_min.minute, entry_min.second,
                entry_min.status, entry_min.code);

                sprintf(str_j, "%04d %02d %02d %02d %02d %02d %01d %03d", entry_j.year, entry_j.month,
                entry_j.day, entry_j.hour, entry_j.minute, entry_j.second, entry_j.status, entry_j.code);

                int res = strcmp(str_min, str_j);

                if (res > 0) {
                    min = j;
                }
            }

            swap_records_in_file(file, i, min);
        }

        fclose(file);
    }

    return 0;
}

int add_entry(FILE *file, char *file_name) {
    char str[1024];
    struct date new_entry;

    fgets(str, 1023, stdin);

    if (sscanf(str, "%d %d %d %d %d %d %d %d", &new_entry.year, &new_entry.month, &new_entry.day, \
    &new_entry.hour, &new_entry.minute, &new_entry.second, &new_entry.status, &new_entry.code) != 8) {
        printf("n/a");
        return 1;
    }

    if ((file = fopen(file_name, "rb+")) == NULL) {
        printf("n/a");
        return 1;
    } else {
        int records_num = get_records_count_in_file(file);

        write_record_in_file(file, &new_entry, records_num);

        fclose(file);
    }

    return 0;
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    struct date record1 = read_record_from_file(pfile, record_index1);
    struct date record2 = read_record_from_file(pfile, record_index2);

    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

void write_record_in_file(FILE *pfile, const struct date *record_to_write, int index) {
    int offset = index * sizeof(struct date);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct date), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

int get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(struct date);
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);

    return size;
}

struct date read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(struct date);
    fseek(pfile, offset, SEEK_SET);
    struct date record;
    fread(&record, sizeof(struct date), 1, pfile);
    rewind(pfile);

    return record;
}
