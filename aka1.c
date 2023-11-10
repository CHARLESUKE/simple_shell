#include "main.h"


/**
 * print_a - performance to imprints an alias string
 * @_clot: alias node
 * Return: returns (0) if success and (1) if failure
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
 * cmd_alias - impersonate the alias order
 * @cmd_dat: construction type
 *  Return: return (0)
 */
int cmd_alias(cmd_d *cmd_dat)
{
	int b = 0;
	char *prompt = NULL;
	list_s *clot = NULL;

	if (cmd_dat->argc == 1)
	{
		clot = cmd_dat->alias;
		while (clot)
		{
			print_a(clot);
			clot = clot->next;
		}
		return (0);
	}
	for (b = 1; cmd_dat->argv[b]; b++)
	{
		prompt = string_char(cmd_dat->argv[b], '=');
		if (prompt)
			alias_set(cmd_dat, cmd_dat->argv[b]);
		else
			print_a(start_node(cmd_dat->alias, cmd_dat->argv[b], '='));
	}

	return (0);
}
