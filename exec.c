#include "main.h"

/**
 * exec - fork, execute, wait function
 * @c_pid: child process
 * @array: double pointer to array of strings
 * @cont: the number of loops from getline
 * Return: 0 or -1
 */

int exec(pid_t c_pid, char **array, int cont)
{
	int status;

	c_pid = fork();
	if (c_pid == -1)
	{
		perror("fork() error: ");
		return (-1);
	}
	if (c_pid == 0)
	{
		if (execve(array[0], array, NULL) == -1)
		{
			if (array[0][0] == '/')
			{
				error(array[0], cont, 1);
				exit(126);
			}
			error(array[0], cont, 0);
			exit(status);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			const int ex_status = WEXITSTATUS(status);

			return (ex_status);
		}
	}
	return (0);
}
