#ifndef S21_STRING_H_
#define S21_STRING_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
char *s21_strchr(const char *str, int c);
char *s21_itoa(int num, char *buf);
size_t s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
int s21_sprintf(char* str, const char *buf, ...);
int s21_atoi(char*buf);
char *s21_strtok(char *str, const char *delim);
char *s21_strpbrk(const char *str1, const char *str2);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, size_t start_index);
#endif  //  S21_STRING_H_