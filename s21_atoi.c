#include "s21_string.h"

int s21_atoi(char*buf) {
    int flag = 0;
    if (buf[0] == '-') {
        flag = 1;
        buf++;
    }
    int len = s21_strlen(buf);
    int result = 0;
    int i = 1;
    int h = 1;
    while (i < len) {
        i++;
        h *= 10;
    }
    for (; *buf != '\0';) {
        result += h *(*buf++ - 48);
        h /= 10;
    }
    if (flag) result = -result;
    return result;
}