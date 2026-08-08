#ifndef STRINGK_H
#define STRINGK_H

#include <stddef.h>

size_t strlen(const char *str);
int strcmpk(const char *str1, const char *str2);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);

#endif