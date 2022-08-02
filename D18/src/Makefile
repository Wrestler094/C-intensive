FLAGS = -Wall -Werror -Wextra

all: build

build: print_module

rebuild: clean build

print_module: print_module.c main_module_entry_point.c
	gcc $(FLAGS) print_module.c main_module_entry_point.c -o ../build/Quest_1

clean:
	rm -rf ./*.o
	rm -rf ../build/Quest_*

clean_o:
	rm -rf ./*.o