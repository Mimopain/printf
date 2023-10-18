#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: String
 *
 * Return: Length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s)
	{
		len++;
		s++;
	}

	return (len);
}

/**
 * _puts - Prints a string to standard output
 * @str: String to print
 * @len: Length of the string
 */
void _puts(char *str, int *len)
{
	while (*str)
	{
		_putchar(*str, len);
		str++;
	}
}

/**
 * _puts_rot13 - Prints a ROT13-encoded string to standard output
 * @str: ROT13-encoded string to print
 * @len: Length of the string
 */
void _puts_rot13(char *str, int *len)
{
	while (*str)
	{
		_putchar_rot13(*str, len);
		str++;
	}
}

/**
 * _puts_upper_hex - Prints a string as uppercase hexadecimal to standard output
 * @str: String to print
 * @len: Length of the string
 */
void _puts_upper_hex(char *str, int *len)
{
	while (*str)
	{
		_putchar(*str, len);
		str++;
	}
}

