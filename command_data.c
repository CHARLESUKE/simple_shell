#include "main.h"

/**
 * set_cmd - start order to structure
 * @command_dat: formation type
 * @avv: argument vector
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
 * clear_cmd - start order structure
 * @command_dat: form type
 */

void clear_cmd(cmd_d *command_dat)
{
	command_dat->arg = NULL;
	command_dat->argv = NULL;
	command_dat->path = NULL;
	command_dat->argc = 0;
}

/**
 * free_cmd - Release order
 * @command_dat: form type
 * @u: returns (empty) and true if deed is successful
 */

void free_cmd(cmd_d *command_dat, int u)
{
	str_free(command_dat->argv);
	command_dat->argv = NULL;
	command_dat->path = NULL;
	if (u)
	{
		if (!command_dat->cmd_buf)
			free(command_dat->arg);
		if (command_dat->env)
			free_list(&(command_dat->env));
		if (command_dat->history)
			free_list(&(command_dat->history));
		if (command_dat->alias)
			free_list(&(command_dat->alias));
		str_free(command_dat->environ);
			command_dat->environ = NULL;
		_free_ptr((void **)command_dat->cmd_buf);
		if (command_dat->readfd > 2)
			close(command_dat->readfd);
		_putchar(BUF_FLUSH);
	}
}
