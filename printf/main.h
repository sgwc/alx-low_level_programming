#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _putstr(char *s);
int _putnbr(int n);
int format_char(va_list , char c);
char _itoa(int n);

#endif MAIN_H
