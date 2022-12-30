#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
    char *result = (char*)str;
    int len = s21_strlen(result);
    for (int i = 0; i < len ;i++) {
        if (i == len) {
            result = NULL;
            break;
        }
        if (str[i] == c) {
            result += i;
            break;
        }
    }
    return result;
}