#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <dirent.h>

/**
 * struct built_in - Struct to handle the built-ins commands
 * @str: input command to handle
 * @next: function pointer to execute the command
 * Description: has a command an function pointer to react to it
 */

typedef struct built_in
{
	char *str;
	struct built_in *next;
} built_in_t;
void _wh(char ***array, int *ex_status, int *cont, pid_t *c_pid);
int _read(int rea, char **buffer);
int _buff(char *buffer, int *cont, int *xflag);
int _read(int rea, char **buffer);
int _result(char ***ar, char **buf, int xfla, int resul);
void handle_sigint(int sig);
void direc_fat(char *str, char **temp);
void obt_dir(void);
int _strcom(char *str_1, char *str_2);
void _cd(char *arg);
extern char **environ;
void print_env(void);
void error(char *str, int cont, int flag);
int _strlen(char *s);
void rev_string(char *s);
char *_itoa(int n);
unsigned int get_pid(void);
unsigned int get_ppid(void);
char *stringdup(const char *str);
int toksize(char *str);
char **tokenize(char *str);
int exec(pid_t c_pid, char **array, int cont);
int str_comp(char **array, int size);
char *_getenv(const char *name);
int _which(char *file);
char *str_concat(char *s1, char *s2, int flag);
int path(char **array, int cont);

#endif
