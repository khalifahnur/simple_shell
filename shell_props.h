#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

/* define buffer */
#define buffer 1024

extern char **environ;

/* main shell.c */
int exec_command(int *exit_status, char *fullpath, char *tokens[]);
int handle_prompts(size_t *length, char **line);
int check_builtins(int cnt, char **tokens, int *exit_status, char **argv);
int _ch(char **argv, char **tokens, char **fullpath, int *exit_status);

int _strlen(char *str);
int _strncmp(char *str1, char *str2, int n);
int check_path(char *path);
char *_which(char *filename, char *path);
int _unsetenv(char *name);
void error_message(char **tokens, char **argv, int *exit_status);
void *_realloc(void *ptr, size_t size);
ssize_t _getline(char **linePtr, size_t *buff_size, FILE *my_file);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);
char *_getenv(char *name);
int _atoi(char *str);


#endif
