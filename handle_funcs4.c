#include "main.h"

/**
 * handle_print_hex - Handles the printing of a hexadecimal number
 * @n: Number to print
 * @is_upper: 1 for uppercase, 0 for lowercase
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @alt: Alternate form flag
 *
 * Return: Number of characters printed
 */
int handle_print_hex(unsigned int n, char is_upper, char buffer[], int flags, int width, int precision, char alt)
{
	int i = 0, len;
	char str[8];

	UNUSED(buffer);
	UNUSED(precision);

	if (n == 0)
		return (print_zero(width, flags));

	while (n > 0)
	{
		str[i] = get_hex_char(n % 16, is_upper);
		n = n / 16;
		i++;
	}

	len = i;

	if (alt)
	{
		if (is_upper)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}

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

	if (alt && (width <= len))
	{
		if (is_upper)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}

	return (alt && (width > len) ? width + 2 : width > len ? width : len);
}

/**
 * handle_print_upper_hex - Handles the printing of an uppercase hexadecimal number
 * @n: Number to print
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 *
 * Return: Number of characters printed
 */
int handle_print_upper_hex(unsigned int n, char buffer[], int flags, int width, int precision)
{
	return handle_print_hex(n, 1, buffer, flags, width, precision, 0);
}

/**
 * handle_print_str_upper_hex - Handles the printing of a string in uppercase hexadecimal
 * @str: String to print
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 *
 * Return: Number of characters printed
 */
int handle_print_str_upper_hex(char *str, char buffer[], int flags, int width, int precision)
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
		_puts_upper_hex(str, &len);
	}

	if (width > len && flags & F_MINUS)
	{
		_puts_upper_hex(str, &len);
		print_positive(len, width, flags);
	}

	if (width <= len)
		_puts_upper_hex(str, &len);

	return (width > len ? width : len);
}

