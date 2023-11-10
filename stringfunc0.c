#include "main.h"


/**
 * _putchar - this functions job writes the character e to the standard output
 * @e: this variable is The character to print
 * Return: should return Successful (0) always
 * but On error, -1 should be or is returned,
 * and errno shoulb be or is set appropriately
 */
int _putchar(char e)
{
	static int j;
	static char buffon[WRITE_BUF_SIZE];

	if (e == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(1, buffon, j);
		j = 0;
	}
	if (e != BUF_FLUSH)
		buffon[j++] = e;
	return (1);
}



/**
 * append_S - this function job is to prints a string
 * @stringfield: this variable job is to a pointer to string
 */
void append_S(char *stringfield)
{
	int j = 0;

	if (!stringfield)
		return;
	while (stringfield[j] != '\0')
	{
		_putchar(stringfield[j]);
		j++;
	}
}
