#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
    char *trim_chars_tmp;
    if (!trim_chars || s21_strlen(trim_chars) == 0) trim_chars_tmp = " ";
    else trim_chars_tmp = (char *)trim_chars;
    int flag = 0;
    char *src_tmp, *tmp;
    if(src) {
        src_tmp = (char *)src;
        int c = s21_strspn(src_tmp, trim_chars_tmp);
        if(c) src_tmp += c;
        int len1 = s21_strlen(src_tmp);
        if (len1) {
            tmp = malloc(sizeof(char) * (len1 + 1));
            for (int i = 0; i < len1; i++) {
                tmp[i] = src_tmp[i];
            }
            tmp[len1] = '\0';
            int len2 = s21_strlen(trim_chars_tmp);
            int k;
            for (int i = len1 - 1; i > 0; i--) {
                k = 0;
                for (int j = 0; j < len2; j++) {  
                    if (tmp[i] == trim_chars_tmp[j]) k++;
                }
                if (k == 0) break;
                else if (k > 0) tmp[i] = '\0';
            }
            flag = 1;
        }
    } 
    return (flag) ? tmp: NULL;
}