#include "s21_string.h"
typedef struct Flags {
    int plus;
    int minus;
    int zero;
    int num;
    int space;
    int s;
    int c;
    int d;
}Flags;
void proc_spec(char **str, const char **format, va_list va, Flags *flags);
void spec_c(char **str, const char **format, va_list va, Flags *flags);
void spec_s(char **str, const char **format, va_list va, Flags *flags);
void spec_d(char **str, const char **format, va_list va, Flags *flags);
void proc_flags(const char **format, Flags *flags);
void check_space(const char **format, Flags *flags);
void check_int_num(const char **format, Flags *flags);
void shift_right(char **str, int len, Flags *flags);
void check_minus(const char **format, Flags *flags) ;

int main() {
    int age = 10;
    char name[16] = "Ira";
    char details[350];
    int i = sprintf(details, "Name: %s\nAge: %i\nName: %s\nnumber = %d\nfruit: %s\nsymb = %5c", name, age, "Izolda", 150, "ananasinka", 'n');
    printf("%s\n", details);
    printf("%d\n", i);
    return 0;
}

/*Ошибки:
1. Пробел в спец. %s
2. Флаги + пробел вместе
*/
void check_space(const char **format, Flags *flags) {
    if (**format == ' ') {
        flags->space = 1;
        // if (flags->plus) exit(1);
    }
}
void check_minus(const char **format, Flags *flags) {
    if (**format == '-') {
        flags->minus = 1;
        // if (flags->plus) exit(1);
    }
}
void check_plus(const char **format, Flags *flags) {
    if (**format == '+') {
        flags->plus = 1;
        if (flags->space) fprintf(stderr, "void check_int_num(const char **format, Flags *flags)");
    }
}

void check_int_num(const char **format, Flags *flags) {
    if (**format >= '1' && **format <= '9') {
        char buf[4096];
        int i = 0;
        while (**format >= '0' && **format <= '9') {
            buf[i++] = *(*format)++;
        }
        buf[i] = '\0';
        flags->num = s21_atoi(buf);
        (*format)--;
    }
}

void proc_flags(const char **format, Flags *flags) {
    (*format)++;
    while(**format != 'c' && **format != 'i' && **format != 'd' && **format != 's') {
        check_space(format, flags);
        check_plus(format, flags);
        check_minus(format, flags);
        check_int_num(format, flags);
        (*format)++;
    }
    (*format)--;
}

void shift_right(char **str, int len, Flags *flags) {
    while (len++ <= flags->num) {
        *(*str)++ = ' ' ;
    }
    (*str)--;
}

void spec_c(char **str, const char **format, va_list va, Flags *flags) {
    if (**format == 'c') {
        if (flags->space) {
            fprintf(stderr, "\033[31mSpace with char ne nado!\033[0m\n");
        }
        if (flags->num && !flags->minus) shift_right(str, 1, flags);
        *(*str)++ = va_arg(va, int);
        if (flags->num && flags-> minus) shift_right(str, 1, flags);
    }
}

void spec_s(char **str, const char **format, va_list va, Flags *flags) {
    if (**format == 's') {
        char *pr_s = va_arg(va, char*);
        while (*pr_s != '\0') {
            *(*str)++ = *pr_s++;
        }
    }
}

void spec_d(char **str, const char **format, va_list va, Flags *flags) {
    if (**format == 'd' || **format == 'i') {
        char pr_int[4096];
        s21_itoa(va_arg(va, int), pr_int);
        int i = 0;
        while (pr_int[i] != '\0') {
            *(*str)++ = pr_int[i++];
        }
    }
}

void proc_spec(char **str, const char **format, va_list va, Flags *flags) {
    (*format)++;
    spec_s(str, format, va, flags);
    spec_d(str, format, va, flags);
    spec_c(str, format, va, flags);
}




int s21_sprintf(char* str, const char *format, ...) {
    va_list va;
    va_start(va, format);
    char *str_start = str;
    while (*format != '\0') {
        if (*format != '%') {
            *str++ = *format++;
        } else {
            Flags flags = {0};
            proc_flags(&format, &flags);
            proc_spec(&str, &format, va, &flags);
            format++;
        }
    }
    *str = '\0';
    int len = s21_strlen(str_start);
    va_end(va);
    return len;
}