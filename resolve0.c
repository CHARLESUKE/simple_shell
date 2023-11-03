#include "main.h"

/**
 * if_exec_cmd - checks or determine if a
 * file at a given path is an executable command
 * @cmd_dat: the command data struct
 * @path: path to the file
 * Return: (1) if true, (0) if false
 */
int if_exec_cmd(cmd_d *cmd_dat, char *path)
{
	struct stat st;

	(void)cmd_dat;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * char_dup - duplicates characters
 * @path_str: the PATH string
 * @start_c: starting character index
 * @stop_c: stopping charcter index
 * Return: returns pointer to new buffer
 */

char *char_dup(char *path_str, int start_c, int stop_c)
{
	static char buff[1024];
	int i = 0;
	int a = 0;

	for (a = 0, i = start_c; i < stop_c; i++)
		if (path_str[i] != ':')
			buff[a++] = path_str[i];
	buff[a] = 0;
	return (buff);
}

