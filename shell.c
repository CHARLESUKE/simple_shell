#include "main.h"

/**
 * main - this function job is the entry point for the simple shell
 * @argu_count: this variable is the argument count
 * @avv: this variable is the argument vector
 * Return: should return (0) if very successful, and (1) if there
 * are errors
 */

int main(int argu_count, char **avv)
{
	cmd_d cmddatarray[] = { CMDDATA_INIT };
	int filedescriptor = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (filedescriptor)
			: "r" (filedescriptor));

	if (argu_count == 2)
	{
		filedescriptor = open(avv[1], O_RDONLY);
		if (filedescriptor == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				append_err_s(avv[0]);
				append_err_s(": 0: access denied ");
				append_err_s(avv[1]);
				err_putchar('\n');
				err_putchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		cmddatarray->readfd = filedescriptor;
	}
	populate_env(cmddatarray);
	rd_history(cmddatarray);
	shell(cmddatarray, avv);
	return (EXIT_SUCCESS);
}
