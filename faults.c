#include "main.h"

/**
 * append_err_s - this function is the engrave an input string
 * @t: this variable is the mistake string to be engraved
 * Return: should always return nothing (void)
 */
void append_err_s(char *t)
{
	int b = 0;

	if (!t || t == NULL)
		return;
	while (t[b] != '\0')
	{
		err_putchar(t[b]);
		b++;
	}
}

/**
 * err_putchar - notes s function is the character e to stderr type
 * @e: this variable is the character to engrave type
 * Return: should always return If successful (1) while if an error happens
 * (-1) is returned, and errno is set properly
 */

int err_putchar(char e)
{
	static int b;
	static char buffer[WRITE_BUF_SIZE];

	if (e == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(2, buffer, b);
		b = 0;
	}
	if (e != BUF_FLUSH)
		buffer[b++] = e;
	return (1);
}
