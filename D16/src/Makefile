CFLAGS = -std=c11 -Wall -Wextra -Werror

all: build

build: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests clean_o

rebuild: clean build

s21_string.o: s21_string.c
	gcc -c $(CFLAGS) s21_string.c -o s21_string.o

# STRLEN

strlen_tests_main.o: s21_string_test.c
	gcc -c $(CFLAGS) -DSTRLEN s21_string_test.c -o strlen_tests_main.o

strlen_tests: strlen_tests_main.o s21_string.o
	gcc strlen_tests_main.o s21_string.o -o ../build/Quest_1

# STRCMP

strcmp_tests_main.o: s21_string_test.c
	gcc -c $(CFLAGS) -DSTRCMP s21_string_test.c -o strcmp_tests_main.o

strcmp_tests: strcmp_tests_main.o s21_string.o
	gcc strcmp_tests_main.o s21_string.o -o ../build/Quest_2

# STRCPY

strcpy_tests_main.o: s21_string_test.c
	gcc -c $(CFLAGS) -DSTRCPY s21_string_test.c -o strcpy_tests_main.o

strcpy_tests:: strcpy_tests_main.o s21_string.o
	gcc strcpy_tests_main.o s21_string.o -o ../build/Quest_3

# STRCAT

strcat_tests_main.o: s21_string_test.c
	gcc -c $(CFLAGS) -DSTRCAT s21_string_test.c -o strcat_tests_main.o

strcat_tests: strcat_tests_main.o s21_string.o
	gcc strcat_tests_main.o s21_string.o -o ../build/Quest_4

# STRCHR

strchr_tests_main.o: s21_string_test.c
	gcc -c $(CFLAGS) -DSTRCHR s21_string_test.c -o strchr_tests_main.o

strchr_tests:: strchr_tests_main.o s21_string.o
	gcc strchr_tests_main.o s21_string.o -o ../build/Quest_5

# CLEAN

clean:
	rm -rf ./*.o
	rm -rf ../build/Quest_*

clean_o:
	rm -rf ./*.o