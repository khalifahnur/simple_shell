#include "shell_props.h"


/**
 * _strcmp - Entry point
 * Description: 'compares two strings'
 *
 *
 * @str1: 'string 1'
 * @str2: 'stri'
 *
 * Return: 'If str1 is lexicographically less than str2,'
 * 'If str1 is lexicographically greater than str2,'
 * 'strcmp returns a positive integer value (usually 1).'
 * 'strcmp returns a negative integer value (usually -1).'
 * 'If str1 is lexicographically equal to str2,'
 * 'strcmp returns (0).'
 */
int _strcmp(char *str1, char *str2)
{
	int z = 0;
	int len1, len2;

	if (str1 == NULL)
		str1 = "";
	if (str2 == NULL)
		str2 = "";
	len1 = _strlen(str1);
	len2 = _strlen(str2);
	if (len1 > len2)
		return (1);
	else if (len1 < len2)
		return (-1);
	while (z < len1)
	{
		if (str1[z] != str2[z])
		{
			return (-1);
		}
		z++;
	}
	return (0);
}
/**
 * _strlen - Entry point
 * Description: 'Find the string length'
 * @str: 'string'
 * Return: length of strings
 */

int _strlen(char *str)
{
	int z = 0;

	if (str == NULL)
		str = ""; /* end if */
	while (*str != '\0')
	{
		z++;
		str++;
	}
	return (z);
}
/**
 * _strcat - Entry poionts
 * Description: 'combine string'
 * @dest: 'destination'
 * @src: 'source'
 * Return: combined string
 */
char *_strcat(char *dest, char *src)
{
	int z = 0;
	char *temp = dest;

	while (*temp != '\0')
	{
		temp++;
	}
	while (z < _strlen(src))
	{
		*temp = src[z];
		temp++;
		z++;
	}
	*temp = '\0';
	return (dest);
}
/**
 * _strdup - Entry point
 * Description: 'duplicate a string'
 * @str: 'string'
 * Return: returns a pointer to a newly allocated memory
 * block containing a duplicate of the input string
 */
char *_strdup(char *str)
{
	char *myStr;
	int i = 0;

	if (str == NULL)
	{
		return (NULL);
	} /* end if */
	myStr = (char *)malloc(strlen(str) * sizeof(char) + 1);
	if (myStr == NULL)
	{
		return (NULL);
	}
	while (i <= (int)strlen(str))
	{
		myStr[i] = str[i];
		i++;
	}
	return (myStr);
}
/**
 * _strcpy - Entry point
 * Description: 'copy strings from src to dest'
 * @src: 'source'
 * @dest: 'destination'
 * Return: output copied string
 */
char *_strcpy(char *dest, char *src)
{
	int z = 0;

	while (z <= _strlen(src))
	{
		dest[z] = src[z];
		z++;
	}
	return (dest);
}

