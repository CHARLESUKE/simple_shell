#include "main.h"


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
