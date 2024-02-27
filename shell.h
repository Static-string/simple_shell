#ifndef _SHELL_H_
#define _SHELL_H_


#include <ctype.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *handle_path(char *args);
int Exit_Command(char **cmd, char *cib, int command_status);
int handleEnv(char **user_command);
void free_array(char **);
int builtin(char **args, char *cmd, int l);
int _atoi(char *k);
int _putchar(char c);
char *_string_dup(const char *string);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char **string_token(char *s, char *delim);
int execute_command(char **args, char *ipb);
int validate(char **args, char *ipb);
void _print_string(const char *string);

#endif
