CC=gcc
CFLAGS=-Wall -Wextra -Werror
FILES=s21_insert.c s21_strchr.c s21_trim.c s21_strcmp.c s21_strlen.c s21_strspn.c s21_strtok.c s21_strstr.c s21_strpbrk.c s21_sprintf.c s21_itoa.c s21_atoi.c
FILES_O=s21_insert.o s21_strchr.o s21_trim.o s21_strcmp.o s21_strlen.o s21_strspn.o s21_strtok.o s21_strstr.o s21_strpbrk.o s21_sprintf.o s21_itoa.o s21_atoi.o
all: build

build: s21_sprintf

s21_sprintf: ${FILES_O} 
	${CC} ${CFLAGS} ${FILES_O} -o s21_sprintf
${FILES_O} : ${FILES} s21_string.h
	${CC} ${CFLAGS} ${FILES} -c

clean:
	rm -rf *.o s21_sprintf

rebuild: clean s21_sprintf