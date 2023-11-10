/**
 * atoi - change the starting part of the string aimed to a integer
 * @str: the string impending changed
 * Return: returns (0) if nueral in string or a set of
 * changed numeral
 */

int atoi(char *str)
{
	int b, result;
	int signal = 1, banner = 0;
	unsigned int rest = 0;

	for (b = 0; str[b] != '\0' && banner != 2; b++)
	{
		if (str[b] == '-')
			signal *= -1;

		if (str[b] >= '0' && str[b] <= '9')
		{
			banner = 1;
			rest *= 10;
			rest += (str[b] - '0');
		}
		else if (banner == 1)
			banner = 2;
	}

	if (signal == -1)
		result = -rest;
	else
		result = rest;

	return (result);
}
