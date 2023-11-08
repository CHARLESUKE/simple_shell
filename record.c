#include "main.h"

/**
 * history_file - this function gets the (record)history file
 * @command_dat: this is the structure(system) type
 * Return: this should return the history file
 */

char *history_file(cmd_d *command_dat)
{
	char *buffon, *_direct;

	_direct = _get_env(command_dat, "HOME=");
	if (!_direct)
		return (NULL);
	buffon = malloc((string_length(_direct) + string_length(HIST_FILE) + 2) *
			sizeof(char));
	if (!buffon)
		return (NULL);
	buffon[0] = 0;
	my_str_copy(buffon, _direct);
	str_concat(buffon, "/");
	str_concat(buffon, HIST_FILE);
	return (buffon);
}



/**
 * rd_history - this function reads the history from the file
 * @command_dat: this is the structure(style) type
 * Return: this should return history_count if successful & (0) if not succ
 */

int rd_history(cmd_d *command_dat)
{
	int b, o = 0, line_count = 0;
	ssize_t recfile_description, read_len, recfile_size = 0;
	struct stat st;
	char *buffon = NULL, *recordfile_name = history_file(command_dat);

	if (!recordfile_name)
		return (0);

	recfile_description = open(recordfile_name, O_RDONLY);
	free(recordfile_name);
	if (recfile_description == -1)
		return (0);
	if (!fstat(recfile_description, &st))
		recfile_size = st.st_size;
	if (recfile_size < 2)
		return (0);
	buffon = malloc(sizeof(char) * (recfile_size + 1));
	if (!buffon)
		return (0);
	read_len = read(recfile_description, buffon, recfile_size);
	buffon[recfile_size] = 0;
	if (read_len <= 0)
		return (free(buffon), 0);
	close(recfile_description);
	for (b = 0; b < recfile_size; b++)
		if (buffon[b] == '\n')
		{
			buffon[b] = 0;
			build_history(command_dat, buffon + o, line_count++);
			o = b + 1;
		}
	if (o != b)
		build_history(command_dat, buffon + o, line_count++);
	free(buffon);
	command_dat->histcount = line_count;
	while (command_dat->histcount-- >= HIST_MAX)
		delete_node(&(command_dat->history), 0);
	number_history(command_dat);
	return (command_dat->histcount);
}

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
