#include "s21_string.h"

size_t s21_strlen(const char *str) {
	const char *p;
	for (p = str; *p; p++) 
		{}
	return p-str;
}