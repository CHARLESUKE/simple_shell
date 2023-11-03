#include "main.h"


/**
 * _putchar - writes the character c to standard outpt
 * @c: The character to print
 * Return: Successful (0)
 * On error, -1 is returned, and errno is set appropriately
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}



/**
 * append_S - prints a string
 * @str: pointer to string
 */
void append_S(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
