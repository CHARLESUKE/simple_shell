#include "main.h"

/**
 * shell - this function is the main shell(s) loop
 * @command_dat: this variable is the parameter
 * @avv: this variable is the argument(s) vector
 * Return: this should return (0) if very successful, and
 * (1) if there is an error or error messages
 */

int shell(cmd_d *command_dat, char **avv)
{
	ssize_t b = 0;
	int builtcmdstu = 0;

	while (b != -1 && builtcmdstu != -2)
	{
		clear_cmd(command_dat);
		if (interactive_shell(command_dat))
			append_S("$ ");
		err_putchar(BUF_FLUSH);
		b = _input(command_dat);
		if (b != -1)
		{
			set_cmd(command_dat, avv);
			builtcmdstu = find_builtIn(command_dat);
			if (builtcmdstu == -1)
				path_cmd(command_dat);
		}
		else if (interactive_shell(command_dat))
			_putchar('\n');
		free_cmd(command_dat, 0);
	}
	write_history(command_dat);
	free_cmd(command_dat, 1);
	if (!interactive_shell(command_dat) && command_dat->status)
		exit(command_dat->status);
	if (builtcmdstu == -2)
	{
		if (command_dat->err_num == -1)
			exit(command_dat->status);
		exit(command_dat->err_num);
	}
	return (builtcmdstu);
}

/**
 * find_builtIn - this function jobs checks for the built in commands
 * @command_dat: this variable is the parameter
 * Return: should return (-1) if the builtin command not found, and
 * (0) if the builtin
 * command is executed successfully
 * and then (1) if its found but not executed successfully
 */
int find_builtIn(cmd_d *command_dat)
{
	int b, retcmdbui = -1;
	builtin_list blcmd[] = {
		{"exit", exit_cmd},
		{"env", my_env},
		{"help", help_cmd},
		{"history", history_cmd},
		{"setenv", set_environ},
		{"unsetenv", unset_environ},
		{"cd", cd_cmd},
		{"alias", cmd_alias},
		{NULL, NULL}
	};

	for (b = 0; blcmd[b].type; b++)
		if (my_str_comp(command_dat->argv[0], blcmd[b].type) == 0)
		{
			command_dat->line_count++;
			retcmdbui = blcmd[b].func(command_dat);
			break;
		}
	return (retcmdbui);
}
