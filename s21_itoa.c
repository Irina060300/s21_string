#include "s21_string.h"

char *s21_itoa(int num, char *buf) {
    if (num < 0) {
        *buf++ = '-';
        num = -num;
    }
    int tmp = num, count = 0;
    while (tmp >= 10) {
        tmp /= 10;
        count++;
    }
    int k, h;
    while (count > 0) {
        k = 0;
        h = 1;
        while (k < count) {
            h *= 10;
            k++;
        }
        *buf++ = num/h + 48;
        num %= h;
        count--;        
    }
    *buf++ = num + 48;
    *buf = '\0';
    return buf;
}