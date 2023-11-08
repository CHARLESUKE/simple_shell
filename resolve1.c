#include "main.h"


/**
 * find_full_path - this function jobs finds the full path of (the)
 * an executable command
 * @command_dat: this variable is the data structure type
 * @pathstring: this variable is the PATH string type
 * @cmdtofind: this variable is the command to find type
 *
 * Return: should return full path of the command if its
 *  found or (NULL) if not found
 */
char *find_full_path(cmd_d *command_dat, char *pathstring, char *cmdtofind)
{
	int b = 0, currposition = 0;
	char *cmdpath;

	if (!pathstring)
		return (NULL);
	if ((string_length(cmdtofind) > 2) && _check(cmdtofind, "./"))
	{
		if (if_exec_cmd(command_dat, cmdtofind))
			return (cmdtofind);
	}
	while (1)
	{
		if (!pathstring[b] || pathstring[b] == ':')
		{
			cmdpath = char_dup(pathstring, currposition, b);
			if (!*cmdpath)
				str_concat(cmdpath, cmdtofind);
			else
			{
				str_concat(cmdpath, "/");
				str_concat(cmdpath, cmdtofind);
			}
			if (if_exec_cmd(command_dat, cmdpath))
				return (cmdpath);
			if (!pathstring[b])
				break;
			currposition = b;
		}
		b++;
	}
	return (NULL);
}
