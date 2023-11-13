#include "main.h"


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
