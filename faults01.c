#include "main.h"

/**
 * err_atoi - changes string inputed to an integer
 * @stringtoconv: string to be changed
 * Return: returns (0) if non digits in string,
 * changed number otherwise (-1) on error(rest)
 */

int err_atoi(char *stringtoconv)
{
	int b = 0;
	unsigned long int rest = 0;

	if (*stringtoconv == '+')
		stringtoconv++;
	for (b = 0;  stringtoconv[b] != '\0'; b++)
	{
		if (stringtoconv[b] >= '0' && stringtoconv[b] <= '9')
		{
			rest *= 10;
			rest += (stringtoconv[b] - '0');
			if (rest > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rest);
}

/**
 * print_err - engrave an error messeg
 * @command_dat: is the parameter and wil return command data struct
 * @stringtoconv:the string (error type)
 * Return: returns (void)
 */

void print_err(cmd_d *command_dat, char *stringtoconv)
{
	append_err_s(command_dat->fname);
	append_err_s(": ");
	print_decimal(command_dat->line_count, STDERR_FILENO);
	append_err_s(": ");
	append_err_s(command_dat->argv[0]);
	append_err_s(": ");
	append_err_s(stringtoconv);
}

/**
 * print_decimal - engraves a decimal number (base 10)
 * @entering: the entry
 * @file_d :the file descriptor
 * Return: numbers of char printed
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
 * rm_comments - changes '#' with '\0'
 * @buffer: string address should be improved
 * Return: returns (0);
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



/**
 * convert_num - modifier function, a duplicate(clone)of itoa
 *@numeral: number
 *@support: framework
 *@myflags: flags
 * Return: returns the transformed result (string)
 */

char *convert_num(long int numeral, int support, int myflags)
{
	static char *array;
	static char buffon[50];
	char signboard = 0;
	char *prompt;
	unsigned long m = numeral;

	if (!(myflags & CONVERT_UNSIGNED) && numeral < 0)
	{
		m = -numeral;
		signboard = '-';

	}
	array = myflags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	prompt = &buffon[49];
	*prompt = '\0';

	do	{
		*--prompt = array[m % support];
		m /= support;
	} while (m != 0);

	if (signboard)
		*--prompt = signboard;
	return (prompt);
}
