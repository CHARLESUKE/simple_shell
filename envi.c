#include "main.h"

/**
 * get_env - s functions job is the duty to supply string
 * array smple of the domain
 * @command_dat: this variable is the layout type
 * Return: should always return the string array sample of the domain
 */

char **get_env(cmd_d *command_dat)
{
	if (!command_dat->environ || command_dat->env_changed)
	{
		command_dat->environ = list_to_str(command_dat->env);
		command_dat->env_changed = 0;
	}
	/*if (strchr(variab, ' ') != NULL)*/
		/* return (NULL);*/
	 /*}*/

	return (command_dat->environ);
}
