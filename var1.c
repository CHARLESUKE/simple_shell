#include "main.h"


/**
 * replace_alias - this function is a replacement for an aliases
 * in the token strings
 * @command_dat: this variable is the structure type
 * Return: should always return (1) if alias is fully replaced,
 * and (0) if notreplaced
 */

int replace_alias(cmd_d *command_dat)
{
	int j;
	list_s *clot;
	char *e;

	for (j = 0; j < 10; j++)
	{
		clot = start_node(command_dat->alias, command_dat->argv[0], '=');
		if (!clot)
			return (0);
		free(command_dat->argv[0]);
		e = string_char(clot->str, '=');
		if (!e)
			return (0);
		e = str_duplicate(e + 1);
		if (!e)
			return (0);
		command_dat->argv[0] = e;
	}
	return (1);
}

/**
 * var_replace - this functions job is to replace variables
 * @command_dat: this variable is the structure parameter type
 * Return: should always return (1) if replaced
 * and (0) if not replaced
 */

int var_replace(cmd_d *command_dat)
{
	int b = 0;
	list_s *clot;

	for (b = 0; command_dat->argv[b]; b++)
	{
		if (command_dat->argv[b][0] != '$' || !command_dat->argv[b][1])
			continue;

		if (!my_str_comp(command_dat->argv[b], "$?"))
		{
			replace_str(&(command_dat->argv[b]),
					str_duplicate(convert_num(command_dat->status, 10, 0)));
			continue;
		}
		if (!my_str_comp(command_dat->argv[b], "$$"))
		{
			replace_str(&(command_dat->argv[b]),
					str_duplicate(convert_num(getpid(), 10, 0)));
			continue;
		}
		clot = start_node(command_dat->env, &command_dat->argv[b][1], '=');
		if (clot)
		{
			replace_str(&(command_dat->argv[b]),
					str_duplicate(string_char(clot->str, '=') + 1));
			continue;
		}
		replace_str(&command_dat->argv[b], str_duplicate(""));

	}
	return (0);
}
