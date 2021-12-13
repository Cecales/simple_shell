#include "main.h"

/**
 * exec - fork, execute, wait function
 * @c_pid: child process
 * @array: double pointer to array of strings
 * @cont: the number of loops from getline
 * Return: 0 or -1
 */

int exec(pid_t c_pid, char **array, int cont, char *cast)
{
	int status = 0;
	(void)cast;

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


int _strtok(char *str, char court, int star, char **com)
{
	int count = 0, count_st = star, count_2 = 0;
	printf("en token entra------------------------- %s\n", com[0]);
	if (str[star] == ' ')
	{
		star++;
		if (str[star] != ' ' && str[star] != '\0')
			count_st = star;
		else
			return (-1);
	}
	
	for (; (str[count_st] != ' ' && str[count_st] != '\0') && str[count_st] != court; count_st++, count++)
		continue;

	if (star < count_st)
	{
		
		com[0] = malloc((count + 1) * sizeof(char));
		printf("***************************\n");
		for (;count > count_2; count_2++, star++)
		{
			com[0][count_2] = str[star];
		}
		
		com[0][count_2] = '\0';
		printf("***************************\n");
		star++;
		
		return (star);
	}
	else
	{
		printf("***************************\n");
		return (star++);
	}
}