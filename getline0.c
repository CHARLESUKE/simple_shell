#include "main.h"

/**
 * my_getline - reads an entire line from stream from STDIN, An alternative
 * to (geline) function
 * @cmd_dat: struct parameter
 * @ptr: address to the pointer to buffer
 * @len: preallocated ptr buffer size
 * Return: size of preallocated size
 */
int my_getline(cmd_d *cmd_dat, char **ptr, size_t *len)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, l;
	size_t j;
	ssize_t k = 0, s = 0;
	char *p = NULL, *new_ptr = NULL;
	char *c;

	p = *ptr;
	if (p && len)
		s = *len;
	if (i == l)
		i = l = 0;

	k = read_buf(cmd_dat, buf, &l);
	if (k == -1 || (k == 0 && l == 0))
		return (-1);

	c = string_char(buf + i, '\n');
	j = c ? 1 + (unsigned int)(c - buf) : l;
	new_ptr = my_realloc(p, s, s ? s + j : j + 1);
	if (!new_ptr) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		string_concat(new_ptr, buf + i, j - i);
	else
		string_copy(new_ptr, buf + i, j - i + 1);

	s += j - i;
	i = j;
	p = new_ptr;

	if (len)
		*len = s;
	*ptr = p;
	return (s);
}


/**
 * input_buffer - buffers chained commands
 * @cmd_dat: structure type
 * @buf:  pointer to the buffer
 * @len: address of length variable
 * Return: bytes read
 */
ssize_t input_buffer(cmd_d *cmd_dat, char **buf, size_t *len)
{
	ssize_t s = 0;
	size_t len_t = 0;

	if (!*len) /* if empty, fill it */
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, signalHandler);
#if USE_GETLINE
		s = getline(buf, &len_t, stdin);
#else
		s = my_getline(cmd_dat, buf, &len_t);
#endif
		if (s > 0)
		{
			if ((*buf)[s - 1] == '\n')
			{
				(*buf)[s - 1] = '\0';
				s--;
			}
			cmd_dat->linecount_flag = 1;
			rm_comments(*buf);
			build_history(cmd_dat, *buf, cmd_dat->histcount++);
			{
				*len = s;
				cmd_dat->cmd_buf = buf;
			}
		}
	}
	return (s);
}	
