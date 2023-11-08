#include "main.h"

/**
 * interactive_shell - this fubction shows if the shell is on interactive mode
 * @command_dat: this variable is the structure
 * Return: this should return (1) if shell is very interactive and (0)
 *  if the shell is not anyway interactive
 */

int interactive_shell(cmd_d *command_dat)
{
	return (isatty(STDIN_FILENO) && command_dat->readfd <= 2);
}
