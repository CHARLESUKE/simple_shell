#include "main.h"

/**
 * alias_set - puts alias to take string input
 * @cmd_dat: construction type
 * @str: string alias
 * Return: always return (0) if success and (1) if
 * there is a failure
 */

int alias_set(cmd_d *cmd_dat, char *str)
{
	char *prompt;

	prompt = string_char(str, '=');
	if (!prompt)
		return (1);
	if (!*++prompt)
		return (alias_unset(cmd_dat, str));

	alias_unset(cmd_dat, str);
	return (add_to_list(&(cmd_dat->alias), str, 0) == NULL);
}

/**
 * alias_unset - deletes alisas order
 * @cmd_dat: construction type
 * @str: the string aka
 * Return: returns (0) if success and (1) if failure
 */
int alias_unset(cmd_d *cmd_dat, char *str)
{
	char *prompt;
	char b;
	int rest;

	prompt = string_char(str, '=');
	if (!prompt)
		return (1);
	b = *prompt;
	*prompt = 0;
	rest = delete_node(&(cmd_dat->alias),
		node_index(cmd_dat->alias, start_node(cmd_dat->alias, str, -1)));
	*prompt = b;
	return (rest);
}


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
