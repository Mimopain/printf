#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct specifier_func - Struct to hold specifier and associated function
 * @specifier: The conversion specifier character
 * @func: The associated function to handle the specifier
 */
typedef struct specifier_func
{
	char specifier;
	int (*func)(va_list, char *, int, int, int, char);
} arg_format;

int _printf(const char *format, ...);

int handle_print_char(va_list args, char *buffer, int flags, int width, int precision, char alt);
int handle_print_str(va_list args, char *buffer, int flags, int width, int precision, char alt);
int handle_print_percent(va_list args, char *buffer, int flags, int width, int precision, char alt);
int handle_print_integer(va_list args, char *buffer, int flags, int width, int precision, char alt);
int handle_print_unsigned(va_list args, char *buffer, int flags, int width, int precision, char alt);
int handle_print_hex(va_list args, char *buffer, int flags, int width, int precision, char alt);
int handle_print_upper_hex(va_list args, char *buffer, int flags, int width, int precision, char alt);
int handle_print_str_rot13(va_list args, char *buffer, int flags, int width, int precision, char alt);
int handle_print_address(va_list args, char *buffer, int flags, int width, int precision, char alt);

int handle_print_n(va_list args, char *buffer, int flags, int width, int precision, char alt);
int handle_print_binary(va_list args, char *buffer, int flags, int width, int precision, char alt);
int handle_print_octal(va_list args, char *buffer, int flags, int width, int precision, char alt);

int handle_print_uint_to_base(va_list args, char *buffer, int base, char is_upper, int flags, int width, int precision, char alt);
int handle_print_unsigned_octal(va_list args, char *buffer, int flags, int width, int precision, char alt);
int handle_print_unsigned_hex(va_list args, char *buffer, int is_upper, int flags, int width, int precision, char alt);
int handle_print_address_hex(va_list args, char *buffer, int is_upper, int flags, int width, int precision, char alt);
int handle_print_unsigned_upper_hex(va_list args, char *buffer, int flags, int width, int precision, char alt);

char get_hex_char(int n, char is_upper);
char get_base_char(int n, char is_upper);
void print_positive(int len, int width, int flags);
int print_zero(int width, int flags);
int _strlen(char *s);
void _puts(char *str, int *len);
void _puts_rot13(char *str, int *len);
void _puts_upper_hex(char *str, int *len);
int print_string(char *str, int flags, int width);
void _putchar(char c, int *count);
void _putchar_rot13(char c, int *count);

#define UNUSED(x) (void)(x)

#define F_MINUS (1 << 0)
#define F_PLUS (1 << 1)
#define F_SPACE (1 << 2)
#define F_HASH (1 << 3)
#define F_ZERO (1 << 4)

#endif /* MAIN_H */

