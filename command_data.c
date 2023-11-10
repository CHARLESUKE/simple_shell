#include "main.h"

/**
 * set_cmd - this functions job is to start order to structure
 * @command_dat: this variables job is the formation type
 * @avv: this variable job is the argument vector
 */

void set_cmd(cmd_d *command_dat, char **avv)
{
	int b = 0;

	command_dat->fname = avv[0];
	if (command_dat->arg)
	{
		command_dat->argv = token(command_dat->arg, " \t");
		if (!command_dat->argv)
		{
			command_dat->argv = malloc(2 * sizeof(char *));
			if (command_dat->argv)
			{
				command_dat->argv[0] = str_duplicate(command_dat->arg);
				command_dat->argv[1] = NULL;
			}
		}
		for (b = 0; command_dat->argv && command_dat->argv[b]; b++)
			;
		command_dat->argc = b;

		replace_alias(command_dat);
		var_replace(command_dat);
	}
}

/**
 * clear_cmd - this functions job is to start order struct
 * @command_dat: this variable is the form type
 */

void clear_cmd(cmd_d *command_dat)
{
	command_dat->arg = NULL;
	command_dat->argv = NULL;
	command_dat->path = NULL;
	command_dat->argc = 0;
}
