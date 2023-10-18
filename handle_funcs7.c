#include "main.h"

/**
 * handle_print_unsigned_hex - Handles the printing of an unsigned hexadecimal number
 * @n: Number to print
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @alt: Alternate form flag
 *
 * Return: Number of characters printed
 */
int handle_print_unsigned_hex(unsigned int n, char buffer[], int flags, int width, int precision, char alt)
{
	return handle_print_unsigned_hex(n, 0, buffer, flags, width, precision, alt);
}

/**
 * handle_print_unsigned_upper_hex - Handles the printing of an unsigned uppercase hexadecimal number
 * @n: Number to print
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @alt: Alternate form flag
 *
 * Return: Number of characters printed
 */
int handle_print_unsigned_upper_hex(unsigned int n, char buffer[], int flags, int width, int precision, char alt)
{
	return handle_print_unsigned_hex(n, 1, buffer, flags, width, precision, alt);
}

