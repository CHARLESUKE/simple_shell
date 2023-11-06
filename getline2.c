#include "main.h"


/**
 * signalHandler - blocks and stops ctrl-C from exiting showing and displaying
 * a practically new prompt
 * @sig_num: this is signal number
 * Return: returns absolutely nothing (void)
 */

void signalHandler(__attribute__((unused))int sig_num)
{
	append_S("\n");
	append_S("$ ");
	_putchar(BUF_FLUSH);
}
