#include "shell_props.h"
/**
 * error_message - prints out error messge
 * @tokens: arry containing user input
 * @argv: command line arguments arry
 * @exit_status: exit status
 * Return: void
 */
void error_message(char **tokens, char **argv, int *exit_status)
{
	char newline = '\n';

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
	write(STDERR_FILENO, ": Illegal number: ", 18);
	write(STDERR_FILENO, tokens[1], _strlen(tokens[1]));
	write(STDERR_FILENO, &newline, 1);
	*exit_status = 2;
}
