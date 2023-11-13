#include "main.h"

/**
 * _get_env - this functions job is to get the
 * value of an environment variables type
 * @command_dat: this variables is the Structure  argument type
 * @title: this variables function is the environment
 * variable name type
 * Return: should return the value of the environment
 */

char *_get_env(cmd_d *command_dat, const char *title)
{
	list_s *m = command_dat->env;
	char *b;

	while (m)
	{
		b = _check(m->str, title);
		if (b && *b)
			return (b);
		m = m->next;
	}
	return (NULL);
}

/**
 * my_env -this function job prints the current environment type
 * @command_dat: this variable is the Structure type
 * Return: should returns(0)
 */

int my_env(cmd_d *command_dat)
{
	print_list_string(command_dat->env);
	return (0);
}
