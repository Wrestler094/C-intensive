CFLAGS = -Wall -Werror -Wextra

all: build

build: state_sort state_search

rebuild: clean build

state_sort: state_sort.c
	gcc $(CFLAGS) state_sort.c -o ../build/Quest_1

state_search: state_search.c
	gcc $(CFLAGS) state_search.c -o ../build/Quest_2

clear_state: clear_state.c
	gcc $(CFLAGS) clear_state.c -o ../build/Quest_3

clean:
	rm -rf ../build/Quest_1