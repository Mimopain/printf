#include "main.h"

/**
 * get_arg_func - Returns a pointer to the appropriate argument handling function
 * @s: Conversion specifier character
 *
 * Return: Pointer to the corresponding function
 */
int (*get_arg_func(char s))(va_list, char *, int, int, int, char)
{
	int i;
	char specifiers[] = "cspdiuxXo%nrR";

	arg_format funcs[] = {
		{'c', handle_print_char},
		{'s', handle_print_str},
		{'p', handle_print_address},
		{'d', handle_print_integer},
		{'i', handle_print_integer},
		{'u', handle_print_unsigned},
		{'x', handle_print_hex},
		{'X', handle_print_upper_hex},
		{'o', handle_print_octal},
		{'%', handle_print_percent},
		{'n', handle_print_n},
		{'r', handle_print_str_rot13},
		{'R', handle_print_str_upper_hex},
		{'\0', NULL}
	};

	for (i = 0; funcs[i].specifier != '\0'; i++)
	{
		if (funcs[i].specifier == s)
		{
			return (funcs[i].func);
		}
	}
	return (NULL);
}

