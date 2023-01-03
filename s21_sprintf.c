#include "s21_string.h"
typedef struct Flags {
    int plus;
    int minus;
    int zero;
    int num_int;
    int precis;
    int point;
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
void shift(char **str, int len, Flags *flags);
void check_minus(const char **format, Flags *flags);
void check_precision(const char **format, Flags *flags);
float s21_atof(char *buf);
void add_zeros(char **str, int len, Flags *flags);
int main() {
    //char name[16] = "Ira";
    char details[350];
    int i = sprintf(details, "Name: %s\nAge: %-10.5dend\nName: %s\nnumber = %dend\nfruit: %s\nsymb = %5cend", "Pizdec", 1000, "Izolda", 150, "ananasinka", 'n');
    //int i = sprintf(details, "Age: %-13.0009dend\nnum= %+15.5d", 1000, 100);
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
        //if (flags->space) fprintf(stderr, "\033[31mspace flag ignored with '+' flag in gnu_printf format\033[0m\n");
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
        flags->num_int = s21_atoi(buf);
        (*format)--;
    }
}

void check_precision(const char **format, Flags *flags) {
    if (**format == '.') {
        flags->point = 1;
        int flag = 0;
        (*format)++;
        while (**format == '0') {
            (*format)++;
        }
        if (**format >= '1' && **format <= '9') {
            flag = 1;
            char buf[4096];
            int i = 0;
            while (**format >= '0' && **format <= '9') {
                buf[i++] = *(*format)++;
            }
            buf[i] = '\0';
            flags->precis = s21_atoi(buf);
            
        }
        (*format)--;
        if (flag == 0) flags->precis = 0; 
        // printf("%d", flags->precis);
        // exit(1);
    }
}
// float s21_atof(char *buf) {
//     float result = 0;
//     int cel = s21_atoi(buf);
//     char *dec = s21_strchr(buf, '.');
//     dec++;
//     int drob = s21_atoi(dec);
//     int len = s21_strlen(dec), i;
//     float dr = (float) drob;
//     for (i = 0; i < len; i++) {
//         dr /= 10;
//     }
//     //printf("%s\ndec = %s\n%d, %f", buf, dec, cel, dr);
//     return 0;
// }
void proc_flags(const char **format, Flags *flags) {
    (*format)++;
    while(**format != 'c' && **format != 'i' && **format != 'd' && **format != 's') {
        check_space(format, flags);
        check_plus(format, flags);
        check_minus(format, flags);
        check_int_num(format, flags);
        check_precision(format, flags);
        (*format)++;
    }
    (*format)--;
}

void shift(char **str, int len, Flags *flags) {
    while (len < flags->num_int) {
        *(*str)++ = ' ' ;
        len++;
    }
}

void spec_c(char **str, const char **format, va_list va, Flags *flags) {
    if (**format == 'c') {
        if (flags->space) {
            fprintf(stderr, "\033[31mSpace with char ne nado!\033[0m\n");
        }
        if (flags->plus) {
            fprintf(stderr, "\033[31mPlus with char ne nado!\033[0m\n");
        }
        if (flags->point) {
            fprintf(stderr, "\033[31mPrecis with char ne nado!\033[0m\n");
        }
        if (flags->num_int && !flags->minus) shift(str, 1, flags);
        *(*str)++ = va_arg(va, int);
        if (flags->num_int && flags->minus) shift(str, 1, flags);
    }
}

void spec_s(char **str, const char **format, va_list va, Flags *flags) {
    if (**format == 's') {
        if (flags->space) {
            fprintf(stderr, "\033[31mSpace with char* ne nado!\033[0m\n");
        }
        if (flags->plus) {
            fprintf(stderr, "\033[31mPlus with char* ne nado!\033[0m\n");
        }
        if (flags->point) {
            fprintf(stderr, "\033[31mPrecis with char* ne nado!\033[0m\n");
        }
        char *pr_s = va_arg(va, char*);
        int len = s21_strlen(pr_s);

        if (flags->num_int && !flags->minus) shift(str, len, flags);
        while (*pr_s != '\0') {
            *(*str)++ = *pr_s++;
        }
        if (flags->num_int && flags->minus) shift(str, len, flags);
    }
}
void add_zeros(char **str, int len, Flags *flags) {
        int diff = flags->precis - len;
        for (int i = 0; i < diff; i++) {
            *(*str)++ = '0';
        }
}

void spec_d(char **str, const char **format, va_list va, Flags *flags) {
    if (**format == 'd' || **format == 'i') {
        if (flags->plus && flags->space) {
            fprintf(stderr, "\033[31mspace flag ignored with '+' flag in gnu_printf format\033[0m\n");
        }
        int num = va_arg(va, int);
        char pr_int[4096];
        s21_itoa(num, pr_int);
        int len_pr = s21_strlen(pr_int);
        int i = 0;

        int len = 0;
        if (flags->space) {
            *(*str)++ = ' ';
            len++;
        }
        if (len_pr < flags->precis) {
            len += flags->precis;
        } else {
            len += len_pr;
        }
        if (flags->plus && num > 0) len++;
        if (flags->num_int && !flags->minus) shift(str, len, flags);

        if (flags->plus && num > 0) *(*str)++ = '+';
        if (len_pr < flags->precis) add_zeros(str, len_pr, flags);
        while (pr_int[i] != '\0') {
            *(*str)++ = pr_int[i++];
        }
        if (flags->num_int && flags->minus) shift(str, len, flags);
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