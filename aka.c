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
