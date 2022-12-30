#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    int len1 = s21_strlen(haystack), len2 = s21_strlen(needle);
    char *str1 = (char*)haystack;
    char *str2 = (char*)needle;
    int i = 0, k = 1;
    int flag = 0;
    for (i = 0; i < len1; i++) {
        if (str1[i] == str2[0]) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        size_t step = i;
        for (k = 1; k < len2; k++) {
            if (str1[k + step] != str2[k]) break;
            step++;
        }
    }
    //return (k == len2) ? str1 + i: str1 + len1;
    return str1 + i;
}