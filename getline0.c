#include "main.h"

/**
 *my_getline - this function reads the whole line
 *from stream from STDIN, Another alternative to(geline) function
 * @command_dat: this variable is the structure parameter type
 * @prompt: this variable is the address to the a pointer to a
 * buffer type
 * @buff_length: this variable is the pre allocated pointer buffersize
 * Return: should always return the size of pre allocated size
 */
int my_getline(cmd_d *command_dat, char **prompt, size_t *buff_length)
{
	static char buffon[READ_BUF_SIZE];
	static size_t j, o;
	size_t k;
	ssize_t l = 0, t = 0;
	char *q = NULL, *brandnew_pointer = NULL;
	char *e;

	q = *prompt;
	if (q && buff_length)
		t = *buff_length;
	if (j == o)
		j = o = 0;

	l = read_buf(command_dat, buffon, &o);
	if (l == -1 || (l == 0 && o == 0))
		return (-1);

	e = string_char(buffon + j, '\n');
	k = e ? 1 + (unsigned int)(e - buffon) : o;
	brandnew_pointer = my_realloc(q, t, t ? t + k : k + 1);
	if (!brandnew_pointer) /* THIS FOR MALLOCC FAILS! */
		return (q ? free(q), -1 : -1);

	if (t)
		string_concat(brandnew_pointer, buffon + j, k - j);
	else
		string_copy(brandnew_pointer, buffon + j, k - j + 1);

	t += k - j;
	j = k;
	q = brandnew_pointer;

	if (buff_length)
		*buff_length = t;
	*prompt = q;
	return (t);
}


/**
 * input_buffer - this function is the buffers bonds orders
 * @command_dat: this variable is the construction type
 * @buffon:  this variable is the pointer to buffer
 * @buff_length: this variable is the address of length variab
 * Return: should always return bytes read
 */
ssize_t input_buffer(cmd_d *command_dat, char **buffon, size_t *buff_length)
{
	ssize_t t = 0;
	size_t len_t = 0;

	if (!*buff_length) /* if its empty, should fill it */
	{
		free(*buffon);
		*buffon = NULL;
		signal(SIGINT, signalHandler);
#if USE_GETLINE
		t = getline(buffon, &len_t, stdin);
#else
		t = my_getline(command_dat, buffon, &len_t);
#endif
		if (t > 0)
		{
			if ((*buffon)[t - 1] == '\n')
			{
				(*buffon)[t - 1] = '\0';
				t--;
			}
			command_dat->linecount_flag = 1;
			rm_comments(*buffon);
			build_history(command_dat, *buffon, command_dat->histcount++);
			{
				*buff_length = t;
				command_dat->cmd_buf = buffon;
			}
		}
	}
	return (t);
}
