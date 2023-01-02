#include "s21_string.h"
void proc_spec(char **str, const char **format, va_list va);
char *s21_itoa(int num, char *buf);
typedef struct Specificators {
    char *spec;
    struct specificators *next;

}Spec;

int s21_sprintf(char* str, const char *buf, ...);

int main() {
    int age = 10;
    char name[30] = "Ira";
    char country[30] = "Rus", 
    details[500];
    int i = s21_sprintf(details, "Name: %s\nAge: %i\nName: %s\nnumber = %d\nfruit: %s\nsymb = %c", name, age, "Izolda", 150, "ananas", 'n');
    printf("%s\n", details);
    printf("%d", i);
    return 0;
}

void proc_spec(char **str, const char **format, va_list va) {
    (*format)++;
    if (**format == 's') {
        char *pr_s = va_arg(va, char*);
        while (*pr_s != '\0') {
            *(*str)++ = *pr_s++;
            
        }
    } else if (**format == 'd' || **format == 'i') {
        char pr_int[4096];
        s21_itoa(va_arg(va, int), pr_int);
        int i = 0;
        while (pr_int[i] != '\0') {
            *(*str)++ = pr_int[i++];
        }
    } else if (**format == 'c') {
        *(*str)++ = va_arg(va, int);
    }
}

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


int s21_sprintf(char* str, const char *format, ...) {
    va_list va;
    va_start(va, format);
    char *str_start = str;
    while (*format != '\0') {
        if (*format != '%') {
            *str++ = *format++;
        } else {
            proc_spec(&str, &format, va);
            format++;
        }
    }
    *str = '\0';
    int len = s21_strlen(str_start);
    va_end(va);
    return len;
}