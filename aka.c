#include "main.h"

/**
 * alias_set - this functions job is to put alias to
 * take string input
 * @comamnd_dat: cthis variables job is the onstruction type
 * @stringfield: this variable is the string alias type
 * Return: should always return (0) if success and (1) if
 * there is a failure
 */

int alias_set(cmd_d *command_dat, char *stringfield)
{
	char *prompt;

	prompt = string_char(stringfield, '=');
	if (!prompt)
		return (1);
	if (!*++prompt)
		return (alias_unset(command_dat, stringfield));

	alias_unset(command_dat, stringfield);
	return (add_to_list(&(command_dat->alias), stringfield, 0) == NULL);
}

/**
 * alias_unset - this functions job is to delete alisas order
 * @command_dat: this variables job is construction type
 * @stringfield: this variable is the string aka type
 * Return: should return (0) if success and (1) if failure
 */
int alias_unset(cmd_d *command_dat, char *stringfield)
{
	char *prompt;
	char b;
	int rest;

	prompt = string_char(stringfield, '=');
	if (!prompt)
		return (1);
	b = *prompt;
	*prompt = 0;
	rest = delete_node(&(command_dat->alias),
		node_index(command_dat->alias, start_node(command_dat->alias, stringfield, -1)));
	*prompt = b;
	return (rest);
}
