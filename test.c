#include "s21_string.h"


int main() {
    // void *result;
    // trim("abagggaba", "a");
    // printf("%p\n", result);
    // char * result = s21_trim(" 1 1 1 fdgdfg    ", " 1");
    // printf("%s", result);
    // free(result);
    char *result = s21_insert("0123456789","abc", 10);
    printf("%s", result);
    free(result);
    // printf("%s\n", strchr_1);
    // char *result = s21_strchr("dfgjdfgj1dfgjdfgjj", '1');
    // int i = s21_strcmp("abaa", "abby");
    // printf("%s\n%d\n", result, i);
    // i = s21_strspn("abaa", "ab");
    // // printf("%s\n%d\n", result, i);
    // char *result;
    // char str[100] = "cvbcbv//tedstd/TEST/trtrt//";
    // char *sep= "/st";
    // result = s21_strtok(str, sep);
    // while (result) {
    //     printf("%s\n", result);
    //     result = s21_strtok(NULL, sep);
    // }
 
    // result = strtok(NULL, sep);
    // printf("%s\n", result);

    // char *result = s21_strpbrk("gryearyg", "a");
    // printf("%s\n", result);
    // return 0;
}

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


char *s21_strchr(const char *str, int c) {
    char *result = (char*)str;
    int len = s21_strlen(result);
    for (int i = 0; i < len ;i++) {
        if (i == len) {
            result = NULL;
            break;
        }
        if (str[i] == c) {
            result += i;
            break;
        }
    }
    return result;
}


size_t s21_strlen(const char *str) {
	const char *p;
	for (p = str; *p; p++) 
		{}
	return p-str;
}


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



