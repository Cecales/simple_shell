#include "main.h"

/**
 * _itoa - converts int to string
 * @n: integer given
 * Return: new string
 */

char *_itoa(int n)
{
	long x;
	int count, adjust;
	char *string;

	string = malloc(sizeof(char) * 12);
	if (string == NULL)
		return (NULL);
	x = n;
	count = 0;
	if (x < 0)
	{
		string[count++] = '-';
		x = x * -1;
	}
	if (x > 9)
	{
		adjust = 10;
		while (x / adjust >= 10)
			adjust = adjust * 10;
		string[count++] = ((x / adjust) + '0');

		while (adjust >= 10)
		{
			adjust = adjust / 10;
			string[count++] = (((x / adjust) % 10)  + '0');
		}
	}
	else
		string[count++] = x + '0';
	string[count] = 0;
	return (string);
}

/**
 * error - This function returns custom error messages
 * @str: The argument at index 0
 * @line: Line count from getline function
 * @flag: To determine which error message to output
 */

void error(char *str, int line, int flag)
{
	char *cont = NULL;
	char *shell = _getenv("_");

	cont = _itoa(line);
	write(STDERR_FILENO, shell, _strlen(shell));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cont, _strlen(cont));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, _strlen(str));

	if (flag == 0)
		write(STDERR_FILENO, ": not found\n", 13);
	else if (flag == 1)
		perror(" ");
	free(cont);
}

/**
 * get_pid - function to get process ID of the calling process
 * Return: pid;
 */

unsigned int get_pid(void)
{
	unsigned int pid;

	pid = getpid();
	return (pid);
}

/**
 * get_ppid - function to return the process ID of the
 * parent process of the calling process
 * Return: ppid
 */

unsigned int get_ppid(void)
{
	unsigned int ppid;

	ppid = getppid();
	return (ppid);
}

void _free(char **tokens)
{
	int i = 1;

	for (; tokens[i] != 0; i++)
		free(tokens[i]);
	free(tokens);
	printf("tamaño de tokens es de -------%lu\n", sizeof(tokens));
}
