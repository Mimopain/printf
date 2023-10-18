#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 * @count: A pointer to the character count
 */
void _putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

/**
 * _putchar_rot13 - Writes a ROT13-encoded character to stdout
 * @c: The character to print
 * @count: A pointer to the character count
 */
void _putchar_rot13(char c, int *count)
{
	char source[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char dest[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	int i;
	int found = 0;

	for (i = 0; source[i] != '\0' && found == 0; i++)
	{
		if (source[i] == c)
		{
			c = dest[i];
			found = 1;
		}
	}

	if (found)
	{
		write(1, &c, 1);
		(*count)++;
	}
	else
	{
		write(1, "_", 1);
		(*count)++;
	}
}

