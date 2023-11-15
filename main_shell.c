#include "shell_props.h"

/**
 * main - simple shell
 * @argc: argument count
 * @argv: argument list
 * Return: exit status
 */
int main(int argc __attribute__((unused)), char **argv)
{
	int cnt, results;
    char *line = NULL;
	size_t length = 0;
    char *tokens[buffer];
	int exit_status = 0;
    char *fullpath;

	while (1)
	{
		results = handle_prompts(&length, &line);
		if (results == 1)
			break; 
		cnt = 0;
		tokens[cnt] = strtok(line, " \t\n");
		while (tokens[cnt] != NULL)
		{
			cnt++;
			tokens[cnt] = strtok(NULL, " \t\n");
		} 
		fullpath = tokens[0];
        tokens[cnt] = NULL;
		results = check_builtins(cnt, tokens, &exit_status, argv);
		if (results == 1)
			break; 
		else if (results == 2)
			continue;
		results = _ch(argv, tokens, &fullpath, &exit_status);
		if (results == 1)
			break;
		else if (result == 2)
			continue; 
		results = exec_command(&exit_status, fullpath, tokens);
		if (results == 1)
			break; 
		else if (results == 2)
			continue; 
	} 
	free(line);
	return (exit_status);
} 



/**
 * handle_prompts - displays prompt and gets input
 * @line: user inpt stored
 * @length: length of inpt
 * Return: null
 */
int handle_prompts(size_t *length, char **line)
{
	int is_interactive = isatty(STDIN_FILENO);
    char newline = '\n';
    ssize_t bytes_read;

	if (is_interactive)
	{
		write(STDOUT_FILENO, "$ ", 2);
	} 
	bytes_read = getline(line, length, stdin);
	if (bytes_read == -1)
	{
		if (is_interactive)
		{
			write(STDOUT_FILENO, &newline, 1);
		} 
	return (1);
	}
	return (0);
}

/**
 * exec_command - creates a child prcess and ouputs command
 * @fullpath: executable command
 * @exit_status: exit status
 * @tokens: array of arguments passed
 * Return: null
 */
int exec_command(int *exit_status, char *fullpath, char *tokens[])
{
	int stats;
    pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("fork");
		return (1);
	} 
	if (child == 0)
	{
		execve(fullpath, tokens, environ);
		*exit_status = 2;
		perror("execve");
		exit(*exit_status);
	} 
	else
	{
		wait(&stats);
		if (WIFEXITED(stats))
		{
			*exit_status = WEXITSTATUS(stats);
		} 
	} 
	if (fullpath != tokens[0])
		free(fullpath);
	return (0);
} 

/**
 * _ch - checks for executable file errors
 * @fullpath: full path of command inputed
 * @argv: command line argument lst
 * @tokens: array of user inpt
 * @exit_status: exit stats
 * Return: null
 */
int _ch(char **argv, char **tokens, char **fullpath, int *exit_status)
{
    char newline = '\n';
    char *path = _getenv("PATH");

	if (access(tokens[0], X_OK) == -1)
	{
		*fullpath = _which(tokens[0], path);
		if (access(*fullpath, X_OK) == -1)
		{
			write(STDERR_FILENO, argv[0], strlen(argv[0]));
			write(STDERR_FILENO, ": 1: ", 5);
			write(STDERR_FILENO, tokens[0], strlen(tokens[0]));
			write(STDERR_FILENO, ": not found", 11);
			write(STDERR_FILENO, &newline, 1);
			*exit_status = 127;
			return (2);
		} /* end if */
	} /* end if */

	return (0);
}

/**
 * check_builtins - check for builtins
 *
 * @cnt: number of arguments passed in shell
 * @tokens: list of shell arguments
 * @argv: command line arguments array
 * @exit_status: exit status
 * Return: void
 */
int check_builtins(int cnt, char **tokens, int *exit_status, char **argv)
{
	char newline = '\n';
    char **env = environ;

	if (cnt < 1)
	{
		return (2);
	}
	if (strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] != NULL)
		{
			if (atoi(tokens[1]))
				if (atoi(tokens[1]) >= 0)
					*exit_status = _atoi(tokens[1]);
				else
					error_message(tokens, argv, exit_status);
			else
			{
				error_message(tokens, argv, exit_status);
			}
		}
		return (1);
	}
	if (strcmp(tokens[0], "env") == 0)
	{
		env = environ;
		while (*env != NULL)
		{
			write(STDOUT_FILENO, *env, strlen(*env));
			write(STDOUT_FILENO, &newline, 1);
			env++;
		}
		return (2);
	}
	if (strcmp(tokens[0], "unsetenv") == 0)
	{
		_unsetenv(tokens[1]);
		return (2);
	}
	return (0);
}
