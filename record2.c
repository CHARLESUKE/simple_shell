#include "main.h"


/**
 * number_history - this function numbers the history list after d update
 * @command_dat:this variable is the Structure(system) arguments
 * Return: this should return the new history counts
 */

int number_history(cmd_d *command_dat)
{
	list_s *currentclot = command_dat->history;
	int y = 0;

	while (currentclot)
	{
		currentclot->num = y++;
		currentclot = currentclot->next;
	}
	return (command_dat->histcount = y);
}
