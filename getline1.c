#include "main.h"


/**
 * _input - gets a line minus the newline
 * @cmd_dat: structure type
 * Return: number of bytes read
 */

ssize_t _input(cmd_d *cmd_dat)
{
	static size_t i, j;
	static size_t l;
	ssize_t s = 0;
	char **buf_ptr = &(cmd_dat->arg), *p;
	static char *buf;

	_putchar(BUF_FLUSH);
	s = input_buffer(cmd_dat, &buf, &l);
	if (s == -1) /* End of file */
		return (-1);
	if (l)
	{
		j = i; /* itertor */
		p = buf + i;

		chain_check(cmd_dat, buf, &j, i, l);
		while (j < l) /* iterate till a semicolon or end */
		{
			if (is_Chain(cmd_dat, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= l)
		{
			i = l = 0; /* reset position and length */
			cmd_dat->cmd_buf_type = CMD_NORM;
		}

		*buf_ptr = p;
		return (string_length(p));
	}

	*buf_ptr = buf;
	return (s); /* return length */
}

/**
 * read_buf - reads an input buffer
 * @cmd_dat: structure type
 * @buf: buffer
 * @s: size of buffer
 * Return: (i)
 */
ssize_t read_buf(cmd_d *cmd_dat, char *buf, size_t *s)
{
	ssize_t i = 0;

	if (*s)
		return (0);
	i = read(cmd_dat->readfd, buf, READ_BUF_SIZE);
	if (i >= 0)
		*s = i;
	return (i);
}
