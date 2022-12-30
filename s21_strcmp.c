#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
    int len1 = s21_strlen(str1), len2 = s21_strlen(str2);
    int result = 0;
    if (len1 > len2) result = 1;
    else if (len2 > len1) result = -1;
    else {
        int i;
        for (i = 0; i < len1; i++) {
            if (str1[i] != str2[i]) break;
        }
        if (str1[i] > str2[i]) result = 1;
        else result = -1;
    }
    return result;
}