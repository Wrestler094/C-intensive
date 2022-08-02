#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort(struct door *doors);
void swap(struct door *a, struct door *b);
void close_doors(struct door *doors);
void print_doors(struct door *doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort(doors);
    close_doors(doors);
    print_doors(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        int min = i;

        for (int j = i; j < DOORS_COUNT; j++) {
            if (doors[j].id < doors[min].id) {
                min = j;
            }
        }

        swap(&doors[i], &doors[min]);
    }
}

void swap(struct door *a, struct door *b) {
    struct door c = *a;
    *a = *b;
    *b = c;
}

void close_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}

void print_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, ", doors[i].id);
        printf("%d\n", doors[i].status);
    }
}
