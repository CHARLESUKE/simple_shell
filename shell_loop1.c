#include "main.h"

/**
 * path_cmd - checks for a command in PATH
 * @cmd_dat: the parameter & returnstruct
 *
 * Return: void
 */
void path_cmd(cmd_d *cmd_dat)
{
	char *_path = NULL;
	int i, j;

	cmd_dat->path = cmd_dat->argv[0];
	if (cmd_dat->linecount_flag == 1)
	{
		cmd_dat->line_count++;
		cmd_dat->linecount_flag = 0;
	}
	for (i = 0, j = 0; cmd_dat->arg[i]; i++)
		if (!is_delimeter(cmd_dat->arg[i], " \t\n"))
			j++;
	if (!j)
		return;

	_path = find_full_path(cmd_dat, _get_env(cmd_dat, "PATH="), cmd_dat->argv[0]);
	if (_path)
	{
		cmd_dat->path = _path;
		fork_c(cmd_dat);
	}
	else
	{
		if ((interactive_shell(cmd_dat) || _get_env(cmd_dat, "PATH=")
					|| cmd_dat->argv[0][0] == '/') && if_exec_cmd(cmd_dat, cmd_dat->argv[0]))
			fork_c(cmd_dat);
		else if (*(cmd_dat->arg) != '\n')
		{
			cmd_dat->status = 127;
			print_err(cmd_dat, "No such file\n");
		}
	}
}
