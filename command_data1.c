#include "main.h"


/**
 * free_cmd - this functions job is to Release order
 * @command_dat: this variable is the form type
 * @u: should always return (empty) and true if deed is
 * absoluely successful
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
