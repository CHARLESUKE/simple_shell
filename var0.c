#include "main.h"

/**
 * is_Chain - this functions job is the test for a chain delimeter
 * @command_dat: this variable is the parameter structure type
 * @buffer: this veariable is the character buffer type
 * @prompt: this variable is the pointer to the current position in
 * buffer type
 * Return: should return (1) if absolutely true
 */

int is_Chain(cmd_d *command_dat, char *buffer, size_t *prompt)
{
	size_t b = *prompt;

	if (buffer[b] == '|' && buffer[b + 1] == '|')
	{
		buffer[b] = 0;
		b++;
		command_dat->cmd_buf_type = CMD_OR;
	}
	else if (buffer[b] == '&' && buffer[b + 1] == '&')
	{
		buffer[b] = 0;
		b++;
		command_dat->cmd_buf_type = CMD_AND;
	}
	else if (buffer[b] == ';')
	{
		buffer[b] = 0;
		command_dat->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*prompt = b;
	return (1);
}

/**
 * chain_check - this functions job is to check for continues chainings
 * @command_dat: this variable is the struct type
 * @buffer: this variable is the char buffer type
 * @bfj: this variable is the current position for address in buffer type
 * @t: this variable is the starting position type
 * @lengthstr: this variable is the buffer's length type
 * Return: should always return absolutely nothing (void)
 */

void chain_check(cmd_d *command_dat, char *buffer, size_t *bfj, size_t t, size_t lengthstr)
{
	size_t q = *bfj;

	if (command_dat->cmd_buf_type == CMD_AND)
	{
		if (command_dat->status)
		{
			buffer[t] = 0;
			q = lengthstr;
		}
	}
	if (command_dat->cmd_buf_type == CMD_OR)
	{
		if (!command_dat->status)
		{
			buffer[t] = 0;
			q = lengthstr;
		}
	}

	*bfj = q;
}

