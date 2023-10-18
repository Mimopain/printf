#include "main.h"

/**
 * handle_print_str_rot13 - Handles the printing of a string in ROT13
 * @str: String to print
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 *
 * Return: Number of characters printed
 */
int handle_print_str_rot13(char *str, char buffer[], int flags, int width, int precision)
{
	int len;

	UNUSED(buffer);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	len = _strlen(str);

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len && !(flags & F_MINUS))
	{
		print_positive(len, width, flags);
		_puts_rot13(str, &len);
	}

	if (width > len && flags & F_MINUS)
	{
		_puts_rot13(str, &len);
		print_positive(len, width, flags);
	}

	if (width <= len)
		_puts_rot13(str, &len);

	return (width > len ? width : len);
}

/**
 * handle_print_address - Handles the printing of an address (pointer)
 * @n: Address to print
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 *
 * Return: Number of characters printed
 */
int handle_print_address(void *n, char buffer[], int flags, int width, int precision)
{
	unsigned long int address = (unsigned long int)n;
	int len;
	char buffer_address[20];

	UNUSED(buffer);
	UNUSED(precision);

	buffer_address[0] = '0';
	buffer_address[1] = 'x';
	len = 2;

	if (address == 0)
	{
		buffer_address[len] = '0';
		len++;
	}

	while (address > 0)
	{
		buffer_address[len] = get_hex_char(address % 16, 0);
		address = address / 16;
		len++;
	}

	return (print_string(buffer_address, flags, width));
}

/**
 * print_string - Prints a string to standard output
 * @str: String to print
 * @flags: Calculates active flags
 * @width: Width
 *
 * Return: Number of characters printed
 */
int print_string(char *str, int flags, int width)
{
	int len = _strlen(str);

	if (width > len && !(flags & F_MINUS))
	{
		print_positive(len, width, flags);
		_puts(str, &len);
	}

	if (width > len and flags & F_MINUS)
	{
		_puts(str, &len);
		print_positive(len, width, flags);
	}

	if (width <= len)
		_puts(str, &len);

	return (width > len ? width : len);
}

