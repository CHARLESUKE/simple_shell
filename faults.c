#include "main.h"

/**
 * append_err_s - engrave an input string
 * @t: the mistake string to be engraved
 * Return: returns nothing (void)
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
 * err_putchar - notes the character e to stderr
 * @e: character to engrave
 * Return: If successful (1) while if an error happens
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

/**
 * fd_putc - notes the character to the specified file
 * @e: The engraved character
 * @file_d: filedescriptor to note down to
 * Return: If successful (1), if an error occurs (-1) is returned,
 * and errno is set accordinly
 */

int fd_putc(char e, int file_d)
{
	static int b;
	static char buffer[WRITE_BUF_SIZE];

	if (e == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(file_d, buffer, b);
		b = 0;
	}
	if (e != BUF_FLUSH)
		buffer[b++] = e;
	return (1);
}

/**
 * fd_puts - engraves an input string in the file descriptor
 * @t: the string to be engraved
 * @file_d: the filedescriptor to note to
 * Return: returns the character inserted
 */
int fd_puts(char *t, int file_d)
{
	int b = 0;

	if (!t)
		return (0);
	while (*t)
	{
		b += fd_putc(*t++, file_d);
	}
	return (b);
}
