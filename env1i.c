#include "main.h"


/**
 * set_env - this functions job is to start a 
 * new domain variable,and change an existing one
 * @command_dat: this variable is the System type
 * @variab: this variable is the string domain variable
 * @w: this variable is the string domain variable worth
 *  Return: always return (0)
 */

int set_env(cmd_d *command_dat, char *variab, char *w)
{
	char *buffer = NULL, *e;
	list_s *clot;

	if (!variab || !w)
		return (0);

	buffer = malloc(string_length(variab) + string_length(w) + 2);
	if (!buffer)
		return (1);
	if (strchr(variab, ' ') != NULL)
	{
		free (buffer);
		return (1);
	}
	my_str_copy(buffer, variab);
	str_concat(buffer, "=");
	str_concat(buffer, w);
	clot = command_dat->env;
	while (clot)
	{
		e = _check(clot->str, variab);
		if (e && *e == '=')
		{
			free(clot->str);
			clot->str = buffer;
			command_dat->env_changed = 1;
			return (0);
		}
		clot = clot->next;
	}
	add_to_list(&(command_dat->env), buffer, 0);
	free(buffer);
	command_dat->env_changed = 1;
	return (0);
}

/**
 * unset_env - this functions job is to remove a domain variable
 * @command_dat: this variable is the System dispute type
 * @variab: this variable is the string domain variable
 *  Return:should  return (1) if delelted, returns (0) if not
 */

int unset_env(cmd_d *command_dat, char *variab)
{
	size_t y = 0;
	list_s *clot = command_dat->env;
	char *prompt;

	if (!variab || !clot)
		return (0);

	while (clot)
	{
		prompt = _check(clot->str, variab);
		if (prompt && *prompt == '=')
		{
			command_dat->env_changed = delete_node(&(command_dat->env), y);
			y = 0;
			clot = command_dat->env;
			continue;
		}
		clot = clot->next;
		y++;
	}
	return (command_dat->env_changed);
}
