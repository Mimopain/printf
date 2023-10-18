#include "main.h"

/**
 * handle_print_uint_to_base - Handles the printing of an unsigned number to a given base
 * @n: Number to print
 * @base: Base for printing (e.g., 8 for octal, 16 for hex)
 * @is_upper: 1 for uppercase, 0 for lowercase
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @alt: Alternate form flag
 *
 * Return: Number of characters printed
 */
int handle_print_uint_to_base(unsigned int n, unsigned int base, char is_upper, char buffer[], int flags, int width, int precision, char alt)
{
	int i = 0, len;
	char str[12];

	UNUSED(buffer);
	UNUSED(precision);

	if (n == 0)
		return (print_zero(width, flags));

	while (n > 0)
	{
		str[i] = get_base_char(n % base, is_upper);
		n = n / base;
		i++;
	}

	len = i;

	if (alt)
	{
		if (base == 8)
			write(1, "0", 1);
		else if (base == 16)
			write(1, is_upper ? "0X" : "0x", 2);
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
		if (base == 8)
			write(1, "0", 1);
		else if (base == 16)
			write(1, is_upper ? "0X" : "0x", 2);
	}

	return (alt && (width > len) ? width + (base == 8 ? 1 : 2) : width > len ? width : len);
}

