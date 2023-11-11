#include "main.h"


/**
 * print_decimal - this function is engraves a decimal number (base 10)
 * @entering: this variable is the entry type
 * @file_d : this variable is the file descriptor
 * Return: should always return the numbers of char printed
 */

int print_decimal(int entering, int file_d)
{
	int b, numbers = 0;
	int (*_myputchar)(char) = _myputchar;
	unsigned int abstain, curring;

	if (file_d == STDERR_FILENO)
		_myputchar = err_putchar;
	if (entering < 0)
	{
		abstain = -entering;
		_myputchar('-');
		numbers++;
	}
	else
		abstain = entering;
	curring = abstain;
	for (b = 1000000000; b > 1; b /= 10)
	{
		if (abstain / b)
		{
			_myputchar('0' + curring / b);
			numbers++;
		}
		curring %= b;
	}
	_myputchar('0' + curring);
	numbers++;

	return (numbers);
}


/**
 * rm_comments - this function changes '#' with '\0'
 * @buffer: this variable is the string address should be improved
 * type
 * Return: should always return (0);
 */

void rm_comments(char *buffer)
{
	int b;

	for (b = 0; buffer[b] != '\0'; b++)
		if (buffer[b] == '#' && (!b || buffer[b - 1] == ' '))
		{
			buffer[b] = '\0';
			break;
		}
}

