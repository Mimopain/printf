#include "main.h"

/**
 * handle_print_unsigned_octal - Handles the printing of an unsigned octal number
 * @n: Number to print
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @alt: Alternate form flag
 *
 * Return: Number of characters printed
 */
int handle_print_unsigned_octal(unsigned int n, char buffer[], int flags, int width, int precision, char alt)
{
	return handle_print_uint_to_base(n, 8, 0, buffer, flags, width, precision, alt);
}

/**
 * handle_print_unsigned_hex - Handles the printing of an unsigned hexadecimal number
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
int handle_print_unsigned_hex(unsigned int n, char is_upper, char buffer[], int flags, int width, int precision, char alt)
{
	return handle_print_uint_to_base(n, 16, is_upper, buffer, flags, width, precision, alt);
}

/**
 * handle_print_address_hex - Handles the printing of an address (pointer) in hexadecimal
 * @n: Address to print
 * @is_upper: 1 for uppercase, 0 for lowercase
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @alt: Alternate form flag
 *
 * Return: Number of characters printed
 */
int handle_print_address_hex(void *n, char is_upper, char buffer[], int flags, int width, int precision, char alt)
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
		buffer_address[len] = get_hex_char(address % 16, is_upper);
		address = address / 16;
		len++;
	}

	if (alt)
	{
		if (is_upper)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}

	return (print_string(buffer_address, flags, width));
}

