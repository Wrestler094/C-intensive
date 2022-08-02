CFLAGS = -Wall -Werror -Wextra

all: build

build: door_struct door_struct.o
	gcc $(CFLAGS) door_struct.o -o ../build/Quest_1
	clean_o

rebuild: clean build

door_struct: dmanager_module.c
	gcc -c $(CFLAGS) dmanager_module.c -o door_struct.o

clean:
	rm -rf ./*.o ../build/Quest_1

clean_o:
	rm -rf ./*.o