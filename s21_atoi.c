#include "s21_string.h"

int s21_atoi(char*buf) {
    int flag = 0;
    if (buf[0] == '-') {
        flag = 1;
        buf++;
    }
    char *buf_head = buf;
    int len = s21_strlen(buf);
    int result = 0;
    int i = 1;
    int h = 1;
    while (i < len) {
        if (*buf == '.') {
            h /= 10;
            break;
        }
        i++;
        buf++;
        h *= 10;
    }
    buf = buf_head;
    for (; *buf != '\0' && *buf != '.';) {
        result += h *(*buf - 48);
        buf++;
        h /= 10;
    }
    if (flag) result = -result;
    return result;
}