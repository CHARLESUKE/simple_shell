#include "main.h"


/**
 * fd_putc - this function is to note the character to the specified file
 * @e: this variable is the engraved character type
 * @file_d: this variables is the filedescriptor to note down to
 * Return: should always return If successful (1), if an error occurs (-1) is returned,
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
 * fd_puts - this function is to engrave an input string in the file descriptor
 * @t: this variabe is the string to be engraved type
 * @file_d: this variable is the filedescriptor to note to type
 * Return: should always return the character inserted
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
