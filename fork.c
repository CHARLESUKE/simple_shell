#include "main.h"

/**
 * fork_c - fork is an exec to run orders
 * @command_dat: is the parameter
 * Return: nothing (void)
 */
void fork_c(cmd_d *command_dat)
{
	pid_t childprocessid;

	childprocessid = fork();
	if (childprocessid == -1)
	{
		perror("Error:");
		return;
	}
	if (childprocessid == 0)
	{
		if (execve(command_dat->path, command_dat->argv, get_env(command_dat)) == -1)
		{
			free_cmd(command_dat, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(command_dat->status));
		if (WIFEXITED(command_dat->status))
		{
			command_dat->status = WEXITSTATUS(command_dat->status);
			if (command_dat->status == 126)
				print_err(command_dat, "Permission denied\n");
		}
	}
}
