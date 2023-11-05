#include "main.h"

/**
 * is_Chain - test for a chain delimeter
 * @cmd_dat: parameter struct
 * @buff: the character buffer
 * @ptr: pointer to the current position in buf
 * Return: returns (1) if true
 */

int is_Chain(cmd_d *cmd_dat, char *buff, size_t *ptr)
{
	size_t a = *ptr;

	if (buff[a] == '|' && buff[a + 1] == '|')
	{
		buff[a] = 0;
		a++;
		cmd_dat->cmd_buf_type = CMD_OR;
	}
	else if (buff[a] == '&' && buff[a + 1] == '&')
	{
		buff[a] = 0;
		a++;
		cmd_dat->cmd_buf_type = CMD_AND;
	}
	else if (buff[a] == ';')
	{
		buff[a] = 0;
		cmd_dat->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*ptr = a;
	return (1);
}

/**
 * chain_check - checks for continue chaining
 * @cmd_dat: the  structure type
 * @buf: the char buffer
 * @adr: current position address in buffer
 * @s: starting position
 * @len: buffer's length
 * Return: returns nothing (void)
 */

void chain_check(cmd_d *cmd_dat, char *buf, size_t *adr, size_t s, size_t len)
{
	size_t p = *adr;

	if (cmd_dat->cmd_buf_type == CMD_AND)
	{
		if (cmd_dat->status)
		{
			buf[s] = 0;
			p = len;
		}
	}
	if (cmd_dat->cmd_buf_type == CMD_OR)
	{
		if (!cmd_dat->status)
		{
			buf[s] = 0;
			p = len;
		}
	}

	*adr = p;
}

