#include "main.h"

/**
 * path_cmd - this function jobs checks for a command in the PATH
 * @command_dat: this variable is the parameter & returnstructure
 *
 * Return: should return void
 */
void path_cmd(cmd_d *command_dat)
{
	char *cmdpath = NULL;
	int j, k;

	command_dat->path = command_dat->argv[0];
	if (command_dat->linecount_flag == 1)
	{
		command_dat->line_count++;
		command_dat->linecount_flag = 0;
	}
	for (j = 0, k = 0; command_dat->arg[j]; j++)
		if (!is_delimeter(command_dat->arg[j], " \t\n"))
			k++;
	if (!k)
		return;

	cmdpath = find_full_path(command_dat, _get_env(command_dat, "PATH="), command_dat->argv[0]);
	if (cmdpath)
	{
		command_dat->path = cmdpath;
		fork_c(command_dat);
	}
	else
	{
		if ((interactive_shell(command_dat) || _get_env(command_dat, "PATH=")
					|| command_dat->argv[0][0] == '/') && if_exec_cmd(command_dat, command_dat->argv[0]))
			fork_c(command_dat);
		else if (*(command_dat->arg) != '\n')
		{
			command_dat->status = 127;
			print_err(command_dat, "No type of file\n");
		}
	}
}
