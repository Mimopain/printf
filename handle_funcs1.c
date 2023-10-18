#include "main.h"

/**
 * handle_print_char - Handles the printing of a character
 * @c: Character to print
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 *
 * Return: Number of characters printed
 */
int handle_print_char(char c, char buffer[], int flags, int width)
{
	if (flags & F_MINUS)
	{
		_putchar(c, &width);
		print_positive(1, width, flags);
	}
	else
	{
		print_positive(1, width, flags);
		_putchar(c, &width);
	}
	return (width);
}

/**
 * handle_print_str - Handles the printing of a string
 * @str: String to print
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 *
 * Return: Number of characters printed
 */
int handle_print_str(char *str, char buffer[], int flags, int width, int precision)
{
	int len;

	UNUSED(buffer);

	if (str == NULL)
		str = "(null)";

	len = _strlen(str);

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len && !(flags & F_MINUS))
	{
		print_positive(len, width, flags);
		_puts(str, &len);
	}

	if (width > len && flags & F_MINUS)
	{
		_puts(str, &len);
		print_positive(len, width, flags);
	}

	if (width <= len)
		_puts(str, &len);

	return (width > len ? width : len);
}

/**
 * handle_print_percent - Handles the printing of a percent character
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 *
 * Return: Number of characters printed
 */
int handle_print_percent(char buffer[], int flags, int width)
{
	UNUSED(buffer);

	if (flags & F_MINUS)
	{
		_putchar('%', &width);
		print_positive(1, width, flags);
	}
	else
	{
		print_positive(1, width, flags);
		_putchar('%', &width);
	}

	return (width);
}

/**
 * handle_print_integer - Handles the printing of an integer
 * @n: Integer to print
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 *
 * Return: Number of characters printed
 */
int handle_print_integer(int n, char buffer[], int flags, int width, int precision)
{
	int length, len;
	char num[12];

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

	if (n < 0)
	{
		num[len++] = '-';
	}

	if (width > length && !(flags & F_ZERO))
	{
		print_positive(len, width, flags);
	}

	if (n < 0)
	{
		_putchar(num[--len], &len);
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

