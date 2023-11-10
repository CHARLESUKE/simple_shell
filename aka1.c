#include "main.h"


/**
 * print_a - this functions job is the performance to imprints
 * an alias string
 * @_clot: this variable is the alias node type
 * Return: should return (0) if success and (1) if at failure
 */
int print_a(list_s *_clot)
{
	char *prompt = NULL;
	char *b = NULL;

	if (_clot)
	{
		prompt = string_char(_clot->str, '=');
		for (b = _clot->str; b <= prompt; b++)
			_putchar(*b);
		_putchar('\'');
		append_S(prompt + 1);
		append_S("'\n");
		return (0);
	}
	return (1);
}

/**
 * cmd_alias - this functions job is to impersonate
 * the alias order
 * @command_dat: this variable is the construction type
 *  Return: should always return (0)
 */
int cmd_alias(cmd_d *command_dat)
{
	int b = 0;
	char *prompt = NULL;
	list_s *clot = NULL;

	if (command_dat->argc == 1)
	{
		clot = command_dat->alias;
		while (clot)
		{
			print_a(clot);
			clot = clot->next;
		}
		return (0);
	}
	for (b = 1; command_dat->argv[b]; b++)
	{
		prompt = string_char(command_dat->argv[b], '=');
		if (prompt)
			alias_set(command_dat, command_dat->argv[b]);
		else
			print_a(start_node(command_dat->alias, command_dat->argv[b], '='));
	}

	return (0);
}
