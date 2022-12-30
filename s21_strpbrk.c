#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
    int len1 = s21_strlen(str1), len2 = s21_strlen(str2);

    int i;
    for (i = 0; i < len1; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) break;
        }
        if (j < len2) break;
    }
    char *str = (char *)str1 + i;
    return str;
}