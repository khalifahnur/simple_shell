#include "shell_props.h"
/**
 * _which - Entry point
 * Description: 'to find the full path name'
 * @path: 'path'
 * @filename: 'file name'
 * Return: full path name if found && 0 if null.
 */
char *_which(char *filename, char *path)
{
	char *tokens[1024];
	char *path_cpy;
	int i;
	char *pathname;

	if (path == NULL)
	{
		return (NULL);
	}
	path_cpy = strdup(path);

	i = 0;
	tokens[i] = strtok(path_cpy, ":");

	while (tokens[i] != NULL)
	{
		pathname = malloc(strlen(tokens[i]) + strlen(filename) + 2);
		_strcpy(pathname, tokens[i]);
		_strcat(pathname, "/");
		_strcat(pathname, filename);

		if (check_path(pathname))
		{
			free(path_cpy);
			return (pathname);
		}

		free(pathname);
		i++;
		tokens[i] = strtok(NULL, ":");
	}

	free(path_cpy);
	return (NULL);
}
/**
 * check_path - Entry point
 *
 * Descritpion: 'checks for path'
 *
 * @path: 'path'
 * Return: 1 - true & 0 - false
 */
int check_path(char *path)
{
	struct stat buff;

	return ((stat(path, &buff) == 0));
}


/**
 * _unsetenv - remove env variable
 * @name: variable name
 * Return: 0 on success
 */
int _unsetenv(char *name)
{
	char **env = environ;
	int environ_cnt = 0, i = 0, j;
	int len, nameLen;
	char **new_arr;

	if (name == NULL)
		return (-1);
	while (*env != NULL)
	{
		environ_cnt++;
		env++;
	}
	new_arr = malloc((environ_cnt + 1) * sizeof(char *));
	if (new_arr == NULL)
		return (-1);
	env = environ;
	nameLen = _strlen(name);
	while (*env != NULL)
	{
		if (_strncmp(name, *env, nameLen) != 0 || (*env)[nameLen] != '=')
		{
			len = _strlen(*env);
			new_arr[i] = malloc((len + 1) * sizeof(char));
			if (new_arr[i] == NULL)
			{
				for (j = 0; j < i; j++)
				{
					free(new_arr[j]);
				}
				free(new_arr);
				return (-1);
			}
			_strcpy(new_arr[i], *env);
			i++;
		}
		env++;
	}
	new_arr[i] = NULL;
	environ = new_arr;
	return (0);
}
/**
 * _strncmp - compare n character of str1 and str2
 * @str1: string 1
 * @str2: string 2
 * @n: number of characters
 * Return: 0 on success
 */
int _strncmp(char *str1, char *str2, int n)
{
	int z = 0;

	while (z < n)
	{
		if (str1[z] != str2[z])
		return (-1);
		z++;
	}
	return (0);
}

/**
 * _getenv - get an environment variable given name
 * @name: name of enviromt variable
 * Return: environment variable value on success
 */
char *_getenv(char *name)
{
	int z;
	int namelen = _strlen(name);

	for (z = 0; environ[z] != NULL; z++)
	{
		if (_strncmp(name, environ[z], namelen) == 0 && environ[z][namelen] == '=')
		{
			return (environ[z] + namelen + 1);
		}
	}

	return (NULL);
}
