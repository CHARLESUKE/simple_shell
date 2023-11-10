#include "main.h"

/**
 * exit_cmd - exit order for shell
 * @cmd_dat: construction
 * Return: (1) ext, returns (0) if cmd_dat.argv[0] != "exit".
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
 * help_cmd - gives you details on changed directories
 * @cmd_dat: structiure holding disoute
 * Return: returns (0)
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
