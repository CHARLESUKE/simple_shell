#include "main.h"

/**
 * exit_cmd -  this functions is the exit order for shell
 * @command_dat: this variable is the construction type
 * Return: (1) ext, should return (0) if cmd_dat.argv[0] != "exit".
 */
int exit_cmd(cmd_d *command_dat)
{
	int a_scan;

	if (command_dat->argv[1])
	{
		a_scan = err_atoi(command_dat->argv[1]);
		if (a_scan == -1)
		{
			command_dat->status = 2;
			print_err(command_dat, "Invalid number: ");
			append_err_s(command_dat->argv[1]);
			err_putchar('\n');
			return (1);
		}
		command_dat->err_num = err_atoi(command_dat->argv[1]);
		return (-2);
	}
	command_dat->err_num = -1;
	return (-2);
}

/**
 * help_cmd - this functions job is to gives you details 
 * on changed directories
 * @command_dat: this variable is the structiure holding disoute
 * Return: should always return (0)
 */

int help_cmd(cmd_d *command_dat)
{
	char **ogg_rrr;

	ogg_rrr = command_dat->argv;
	append_S("task do not exist \n");
	if (0)
	{
		append_S(*ogg_rrr);
	}
	return (0);
}
