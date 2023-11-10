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
