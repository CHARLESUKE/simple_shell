/**
 * atoi - this functions job is to change the starting part 
 * of the string aimed to a integer
 * @stringfield: this variables job is the string 
 * impending changed
 * Return: shuld return (0) if the nueral in string or a set of
 * changed numeral
 */

int atoi(char *stringfield)
{
	int b, result;
	int signal = 1, banner = 0;
	unsigned int rest = 0;

	for (b = 0; stringfield[b] != '\0' && banner != 2; b++)
	{
		if (stringfield[b] == '-')
			signal *= -1;

		if (stringfield[b] >= '0' && stringfield[b] <= '9')
		{
			banner = 1;
			rest *= 10;
			rest += (stringfield[b] - '0');
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
