#include "main.h"

/**
 * path_cmd - this function jobs checks for a command in the PATH
 * @comdat: this variable is the parameter & returnstructure
 *
 * Return: should return void
 */
void path_cmd(cmd_d *comdat)
{
	char *cmdpath = NULL;
	int j, k;

	comdat->path = comdat->argv[0];
	if (comdat->linecount_flag == 1)
	{
		comdat->line_count++;
		comdat->linecount_flag = 0;
	}
	for (j = 0, k = 0; comdat->arg[j]; j++)
		if (!is_delimeter(comdat->arg[j], " \t\n"))
			k++;
	if (!k)
		return;

	cmdpath = find_full_path(comdat, _get_env(comdat, "PATH="), comdat->argv[0]);
	if (cmdpath)
	{
		comdat->path = cmdpath;
		fork_c(comdat);
	}
	else
	{
		if ((interactive_shell(comdat) || _get_env(comdat, "PATH=")
					|| comdat->argv[0][0] == '/') && if_exec_cmd(comdat, comdat->argv[0]))
			fork_c(comdat);
		else if (*(comdat->arg) != '\n')
		{
			comdat->status = 127;
			print_err(comdat, "No type of file\n");
		}
	}
}
