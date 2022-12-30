#include "s21_string.h"

size_t s21_strspn(const char *str1, const char *str2) {
    int len1 = s21_strlen(str1), len2 = s21_strlen(str2);
    size_t result = 0;
    for (int i = 0; i < len1; i++) {
        int j = 0, flag = 0;
        for (j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) flag = 1;
        }
        if (flag) result++;
        else break;
    }
    return result;
}