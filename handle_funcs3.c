#include "main.h"

/**
 * handle_print_unsigned - Handles the printing of an unsigned number
 * @n: Number to print
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 *
 * Return: Number of characters printed
 */
int handle_print_unsigned(unsigned int n, char buffer[], int flags, int width, int precision)
{
	int length, len;
	char num[10];

	UNUSED(buffer);
	UNUSED(precision);

	if (n == 0)
		return (print_zero(width, flags));

	len = 0;
	while (n)
	{
		num[len++] = (n % 10) + '0';
		n = n / 10;
	}

	length = len;

	if (width > length && !(flags & F_ZERO))
	{
		print_positive(len, width, flags);
	}

	while (len > 0)
	{
		_putchar(num[--len], &len);
	}

	if (width > length && (flags & F_ZERO))
	{
		print_positive(len, width, flags);
	}

	return (width > length ? width : length);
}

/**
 * handle_print_binary - Handles the printing of a binary number
 * @n: Number to print
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 *
 * Return: Number of characters printed
 */
int handle_print_binary(unsigned int n, char buffer[], int flags, int width, int precision)
{
	int i = 0, len;
	char str[32];

	UNUSED(buffer);
	UNUSED(precision);

	if (n == 0)
		return (print_zero(width, flags));

	while (n > 0)
	{
		str[i] = (n % 2) + '0';
		n = n / 2;
		i++;
	}

	len = i;

	if (width > len && !(flags & F_ZERO))
	{
		print_positive(len, width, flags);
	}

	while (i > 0)
	{
		_putchar(str[i - 1], &i);
	}

	if (width > len && (flags & F_ZERO))
	{
		print_positive(len, width, flags);
	}

	return (width > len ? width : len);
}

/**
 * handle_print_octal - Handles the printing of an octal number
 * @n: Number to print
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 *
 * Return: Number of characters printed
 */
int handle_print_octal(unsigned int n, char buffer[], int flags, int width, int precision)
{
	int i = 0, len;
	char str[12];

	UNUSED(buffer);
	UNUSED(precision);

	if (n == 0)
		return (print_zero(width, flags));

	while (n > 0)
	{
		str[i] = (n % 8) + '0';
		n = n / 8;
		i++;
	}

	len = i;

	if (width > len && !(flags & F_ZERO))
	{
		print_positive(len, width, flags);
	}

	while (i > 0)
	{
		_putchar(str[i - 1], &i);
	}

	if (width > len && (flags & F_ZERO))
	{
		print_positive(len, width, flags);
	}

	return (width > len ? width : len);
}

