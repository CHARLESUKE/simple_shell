#include "main.h"

/**
 * if_exec_cmd - this function scan or decide if a
 * file at the handed path is executable command
 * @command_dat: this variable is the the command data
 * structure
 * @pathway: this variable is the path to the file
 * Return:should return (1) if its true, (0) if false if not
 */
int if_exec_cmd(cmd_d *command_dat, char *pathway)
{
	struct stat sti;

	(void)command_dat;
	if (!pathway || stat(pathway, &sti))
		return (0);

	if (sti.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * char_dup - this functions work photocopies characters
 * @pathstring: this variable is the PATH to string
 * @begin_index:this variable begins character index
 * @halt_index: this variable halts charcter index
 * Return: should return pointer to the new buff
 */

char *char_dup(char *pathstring, int begin_index, int halt_index)
{
	static char buffer[1024];
	int j = 0;
	int b = 0;

	for (b = 0, j = begin_index; j < halt_index; j++)
		if (pathstring[j] != ':')
			buffer[b++] = pathstring[j];
	buffer[b] = 0;
	return (buffer);
}

