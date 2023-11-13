#include "main.h"


/**
 * cd_cmd - this jobs fuctions job is to swap directories
 * @command_dat: this variable is the  construction
 * containing potential arguments
 * Return: should always return (0)
 */

int cd_cmd(cmd_d *command_dat)
{
	char *e, *f; /* the f stands for directory */
	char buffer[1024];
	int chndir;

	e = getcwd(buffer, 1024);
	if (!e)
		append_S("TODO: >>getcwd failed emsg spot<<\n");
	if (!command_dat->argv[1])
	{
		f = _get_env(command_dat, "HOME=");
		if (!f)
			chndir = chdir((f = _get_env(command_dat, "PWD=")) ? f : "/");
		else
			chndir = chdir(f);
	}
	else if (my_str_comp(command_dat->argv[1], "-") == 0)
	{
		if (!_get_env(command_dat, "OLDPWD="))
		{
			append_S(e);
			_putchar('\n');
			return (1);
		}
		append_S(_get_env(command_dat, "OLDPWD=")), _putchar('\n');
		chndir = chdir((f = _get_env(command_dat, "OLDPWD=")) ? f : "/");
	}
	else
		chndir = chdir(command_dat->argv[1]);
	if (chndir == -1)
	{
		print_err(command_dat, "cannot cd into ");
		append_err_s(command_dat->argv[1]), err_putchar('\n');
	}
	else
	{
		set_env(command_dat, "OLDPWD", _get_env(command_dat, "PWD="));
		set_env(command_dat, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * history_cmd - this functions job is to list the recorded list
 * @command_dat: this variable is the system type
 *  Return: should always return (0)
 */
int history_cmd(cmd_d *command_dat)
{
	prints_element(command_dat->history);
	return (0);
}
