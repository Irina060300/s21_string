#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *p;
  char *k;
  int flag = 0;
  if (!str) {
    str = p;
  }
  int count = 0, fl;
  for (int i = 0; str[i]!= '\0'; i++) {
    fl = 0;
    for (int j = 0; delim[j] != '\0'; j++) {
        if (delim[j] == str[i]) {
            count++;
            fl = 1;
            break;
        }
    }
    if (fl == 0) break;
  }
  str += count;
  k = str;
  for (int i = 0; *str != '\0' && !flag; i++) {
    for (int j = 0; delim[j] != '\0' && *str != '\0'; j++) {
      if (*str == delim[j]) {
        *str = '\0';
        flag = 1;
      }
    }
    str++;
  }
  p = str;
  return (k[0] == '\0') ? NULL : k;
}