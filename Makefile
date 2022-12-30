CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
FILES=s21_insert.c s21_strchr.c s21_trim.c s21_strcmp.c s21_strlen.c  s21_strspn.c s21_strtok.c s21_strstr.c s21_strpbrk.c test.c
all: build

build: test

test: test.o
	${CC} ${CFLAGS} test.o -o test
test.o: ${FILES} s21_string.h
	${CC} ${CFLAGS} ${FILES} -c

clean:
	rm -rf *.o test

rebuild: clean test