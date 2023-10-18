#include "main.h"

/**
 * get_hex_char - Returns the corresponding hex char
 * @n: Integer to convert
 * @is_upper: 1 for uppercase, 0 for lowercase
 *
 * Return: Corresponding hex char
 */
char get_hex_char(int n, char is_upper)
{
	return ((n < 10) ? n + '0' : (is_upper ? 'A' : 'a') + n - 10);
}

/**
 * get_base_char - Returns the corresponding base char
 * @n: Integer to convert
 * @is_upper: 1 for uppercase, 0 for lowercase
 *
 * Return: Corresponding base char
 */
char get_base_char(int n, char is_upper)
{
	return (n + (is_upper ? 'A' : 'a'));
}

/**
 * print_positive - Prints positive characters
 * @len: Number of characters
 * @width: Width
 * @flags: Calculates active flags
 */
void print_positive(int len, int width, int flags)
{
	char pad_char = ' ';

	if (flags & F_ZERO)
		pad_char = '0';

	while (width > len)
	{
		_putchar(pad_char, &len);
	}
}

/**
 * print_zero - Prints '0' with necessary formatting
 * @width: Width
 * @flags: Calculates active flags
 *
 * Return: Number of characters printed
 */
int print_zero(int width, int flags)
{
	print_positive(1, width, flags);
	return (width > 1 ? width : 1);
}

