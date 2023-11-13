#include "main.h"


/**
 * signalHandler - this functions job blocks and stops ctrl-C
 * from exiting showing and displaying a practically new prompt
 * @sig_num: this variable job is the signal number
 * Return: should always return absolutely nothing (void)
 */

void signalHandler(__attribute__((unused))int sig_num)
{
	append_S("\n");
	append_S("$ ");
	_putchar(BUF_FLUSH);
}
