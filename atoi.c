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


/**
 * alpha_is - examine for alphabetum
 * @e: the intake character
 * Return: returns (1) if true and (0) if false
 */

int alpha_is(int e)
{
	if ((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z'))
		return (1);
	else
		return (0);
}


/**
 * is_delimeter - checks if character is a delimeter
 * @e: character to examine
 * @f: the delimeter
 * Return: returns (1) if there is a delimeter, (0) if false
 */
int is_delimeter(char e, char *f)
{
	while (*f)
		if (*f++ == e)
			return (1);
	return (0);
}
