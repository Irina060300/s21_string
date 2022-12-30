#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
    int flag = 0;
    char *result;
    if (src && str) {
        flag = 1;
        char *src_tmp = (char *)src;
        char *str_tmp = (char *)str;
        int len1 = s21_strlen(src_tmp);
        int len2 = s21_strlen(str_tmp);
        if ((int)start_index <= len1) {
            result = malloc(sizeof(char) * (len1 + len2 + 2));
            int k = 0;
            for (int i = 0; i < len1 + 1; i++) {
                if (i == (int)start_index) {
                    for (int j = 0; j < len2 ; j++) {
                        result[k++] = str_tmp[j];
                    }
                    result[k++] = src_tmp[i];
                } else {
                    result[k++] = src_tmp[i];
                }
            }
            result[k] = '\0';
        } else flag = 0;
    }
    return (flag) ? result: NULL;
}