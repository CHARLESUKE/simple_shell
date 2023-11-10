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

/**
 * set_environ - this functions job is to Initialize(sets) new env
 * ironment variable,and also improve an already existing one
 * @command_dat: this variable is the Structure type.
 *  Return: shoud always returns (0)
 */

int set_environ(cmd_d *command_dat)
{
	if (command_dat->argc != 3)
	{
		append_err_s("Arguments incomplete\n");
		return (1);
	}
	if (set_env(command_dat, command_dat->argv[1], command_dat->argv[2]))
		return (0);
	return (1);
}

/**
 * unset_environ - this functions job is to totally deletes an
 * environment variable
 * @command_dat: this varaible is the Structure argument type
 * Return: this should return (0) always
 */

int unset_environ(cmd_d *command_dat)
{
	int b;

	if (command_dat->argc == 1)
	{
		append_err_s("Arguements just too few.\n");
		return (1);
	}
	for (b = 1; b <= command_dat->argc; b++)
		unset_env(command_dat, command_dat->argv[b]);

	return (0);
}

/**
 * populate_env - this functions job is to populate
 * environment linked list
 * @command_dat: this variable is the Struct type
 * Return: should always return the environment list
 */

int populate_env(cmd_d *command_dat)
{
	list_s *clot = NULL;
	size_t b;

	for (b = 0; environ[b]; b++)
		add_node(&clot, environ[b], 0);
	command_dat->env = clot;
	return (0);
}
