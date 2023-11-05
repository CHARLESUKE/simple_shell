#include "main.h"


/**
 * replace_alias - replaces an aliases in the token strings
 * @cmd_dat: the struct type
 * Return: returns (1) if alias is replaced, and (0) if not
 */

int replace_alias(cmd_d *cmd_dat)
{
	int i;
	list_s *node;
	char *c;

	for (i = 0; i < 10; i++)
	{
		node = start_node(cmd_dat->alias, cmd_dat->argv[0], '=');
		if (!node)
			return (0);
		free(cmd_dat->argv[0]);
		c = string_char(node->str, '=');
		if (!c)
			return (0);
		c = str_duplicate(c + 1);
		if (!c)
			return (0);
		cmd_dat->argv[0] = c;
	}
	return (1);
}

/**
 * var_replace - replaces variables
 * @cmd_dat: struct parameter
 * Return: returns (1) if replaced and (0) if not
 */

int var_replace(cmd_d *cmd_dat)
{
	int a = 0;
	list_s *node;

	for (a = 0; cmd_dat->argv[a]; a++)
	{
		if (cmd_dat->argv[a][0] != '$' || !cmd_dat->argv[a][1])
			continue;

		if (!my_str_comp(cmd_dat->argv[a], "$?"))
		{
			replace_str(&(cmd_dat->argv[a]),
					str_duplicate(convert_num(cmd_dat->status, 10, 0)));
			continue;
		}
		if (!my_str_comp(cmd_dat->argv[a], "$$"))
		{
			replace_str(&(cmd_dat->argv[a]),
					str_duplicate(convert_num(getpid(), 10, 0)));
			continue;
		}
		node = start_node(cmd_dat->env, &cmd_dat->argv[a][1], '=');
		if (node)
		{
			replace_str(&(cmd_dat->argv[a]),
					str_duplicate(string_char(node->str, '=') + 1));
			continue;
		}
		replace_str(&cmd_dat->argv[a], str_duplicate(""));

	}
	return (0);
}
