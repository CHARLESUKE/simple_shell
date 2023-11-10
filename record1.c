#include "main.h"

/**
 * write_history - dis function buids a new file,or do chan to an existing file
 * @command_dat: this is the structure(system) type
 * Return: this should returns (1) if its successful and (-1) if its not
 */
int write_history(cmd_d *command_dat)
{
	char *thef_name = history_file(command_dat);
	ssize_t recfile_description;
	list_s *clot = NULL;

	if (!thef_name)
		return (-1);

	recfile_description = open(thef_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(thef_name);
	if (recfile_description == -1)
		return (-1);
	for (clot = command_dat->history; clot; clot = clot->next)
	{
		fd_puts(clot->str, recfile_description);
		fd_putc('\n', recfile_description);
	}
	fd_putc(BUF_FLUSH, recfile_description);
	close(recfile_description);
	return (1);
}


/**
 * build_history - this function adds to the history linked list
 * @command_dat: this is the Structure(system) arguments
 * @buffon: this is the buffer
 * @count_line: this variable is the history count
 * Return: should return (0)
 */

int build_history(cmd_d *command_dat, char *buffon, int count_line)
{
	list_s *m = NULL;

	if (command_dat->history)
		m = command_dat->history;
	add_to_list(&m, buffon, count_line);

	if (!command_dat->history)
		command_dat->history = m;
	return (0);
}
