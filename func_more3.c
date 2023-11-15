/**
 * _atoi - convert string to integer
 * @str: given string
 * Return: integer
 */
int _atoi(char *str)
{
	int results = 0;
	int z = 0;
	int is_positive = 1;

	if (str[0] == '-')
	{
		is_positive = -1;
		z = 1;
	}

	while (str[z] != '\0')
	{
		if (str[z] >= '0' && str[z] <= '9')
		{
			results = results * 10 + (str[z] - '0');
			z++;
		}
		else
		{
			break;
		}
	}
	return (is_positive * results);
}
