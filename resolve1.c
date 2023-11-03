#include "main.h"


/**
 * find_full_path - finds the full path of an executable command
 * @cmd_dat: the data structure
 * @path_str: the PATH string
 * @cmd: the command to find
 *
 * Return: full path of command if found or (NULL) if not
 */
char *find_full_path(cmd_d *cmd_dat, char *path_str, char *cmd)
{
	int a = 0, current_p = 0;
	char *_path;

	if (!path_str)
		return (NULL);
	if ((string_length(cmd) > 2) && _check(cmd, "./"))
	{
		if (if_exec_cmd(cmd_dat, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!path_str[a] || path_str[a] == ':')
		{
			_path = char_dup(path_str, current_p, a);
			if (!*_path)
				str_concat(_path, cmd);
			else
			{
				str_concat(_path, "/");
				str_concat(_path, cmd);
			}
			if (if_exec_cmd(cmd_dat, _path))
				return (_path);
			if (!path_str[a])
				break;
			current_p = a;
		}
		a++;
	}
	return (NULL);
}
