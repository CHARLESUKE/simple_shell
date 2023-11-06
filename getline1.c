#include "main.h"


/**
 * _input - recieves a line minus the newline
 * @command_dat: anatomy type
 * Return: the number of bytes studied
 */

ssize_t _input(cmd_d *command_dat)
{
	static size_t j, k;
	static size_t o;
	ssize_t t = 0;
	char **buffer_pointer = &(command_dat->arg), *q;
	static char *buffon;

	_putchar(BUF_FLUSH);
	t = input_buffer(command_dat, &buffon, &o);
	if (t == -1) /* Ends of the file */
		return (-1);
	if (o)
	{
		k = j; /*h itertor */
		q = buffon + j;

		chain_check(command_dat, buffon, &k, j, o);
		while (k < o) /* iterate untill hit a semicolon or end(finish) */
		{
			if (is_Chain(command_dat, buffon, &k))
				break;
			k++;
		}

		j = k + 1;
		if (j >= o)
		{
			j = o = 0; /* should reset the position and also the length */
			command_dat->cmd_buf_type = CMD_NORM;
		}

		*buffer_pointer = q;
		return (string_length(q));
	}

	*buffer_pointer = buffon;
	return (t); /* should return length */
}

/**
 * read_buf - this reads (the)an input buffer
 * @command_dat: anatomy type
 * @buffon: buffer
 * @t: thats the total size of buffer
 * Return: (j)
 */
ssize_t read_buf(cmd_d *command_dat, char *buffon, size_t *t)
{
	ssize_t j = 0;

	if (*t)
		return (0);
	j = read(command_dat->readfd, buffon, READ_BUF_SIZE);
	if (j >= 0)
		*t = j;
	return (j);
}
