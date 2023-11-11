#include "main.h"

/**
 * err_atoi - this function job is to change string inputed
 * to an integer
 * @stringtoconv: this variable is the string to be changed
 * type
 * Return: should always return (0) if non digits in string,
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
 * print_err - this functions job is to engrave an error messeg
 * @command_dat: this variable is the parameter and wil return command
 * data struct
 * @stringtoconv: this variable is the the string (error type)
 * Return: should alaways return (void)
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
