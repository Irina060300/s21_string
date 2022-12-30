#include <stdio.h>
#include <string.h>
#include <stdarg.h>


int s21_sprintf(char* str, const char *buf, ...);
int main() {
int age = 10;
char name[30] = "Ira\n";
char country[30] = "Rus\n", 
details[100];


//sprintf(details, "Name: %s Age: %+d Country: %s ", name, age, country);
//printf("details: \n\n %s", details);


s21_sprintf(details,"Name: %s Age: %+d Country: %s ", name, age, country);
return 0;
}

int s21_sprintf(char* str, const char *format, ...) {
    va_list va;
    va_start(va, format);
    char *str_start = str;
    while (*format) {
        if (*format != '%') {
            *str++ = *format++;
            continue;
        } else{
            format++;
        }
    }
    va_end(va);

}