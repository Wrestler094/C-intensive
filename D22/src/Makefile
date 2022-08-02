CFLAGS = -Wall -Werror -Wextra

all: build

build: cipher

rebuild: clean build

cipher: cipher.c
	gcc $(CFLAGS) cipher.c -o ../build/cipher

logging_cipher: logger.c
	gcc $(CFLAGS) logger.c -o ../build/logger

clean:
	rm -rf ../build/cipher