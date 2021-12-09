#include "main.h"

/**
 * path - a function that handles path.
 * How? Takes the command that was typed in the shell, checks
 * in which directory inside PATH the command is located and
 * executes the command.
 * @array: an array of string pointers.
 * @cont: the loop counter from getline
 * Return: return concatenated string; otherwise: NULL.
 */

int path(char **array, int cont)
{
	char *path_original = _getenv("PATH"), *path_copy = stringdup(path_original);
	char *token, *ptr = array[0], *cats;
	pid_t c_pid = 0;
	int ex_status = 0;

	if (_which(array[0]) == 0)
	{
		_wh(&array, &ex_status, &cont, &c_pid);
		free(path_copy);
		return (ex_status);
	}
	else
	{
		token = strtok(path_copy, ":");
		while (token != NULL)
		{
			cats = str_concat(token, ptr, 1);
			if (_which(cats) == 0)
			{
				if (access(cats, X_OK) == 0)
				{
					array[0] = cats;
					ex_status = exec(c_pid, array, cont);
					free(cats);
					free(path_copy);
					return (ex_status);
				}
				else
				{
					free(path_copy);
					error(array[0], cont, 1);
					return (2);
				}
			}
			token = strtok(NULL, ":");
			free(cats);
		}
		
		free(path_copy);
		error(array[0], cont, 0);
	}
	return (127);
}
/**
 * _cd - Struct to handle the built-ins commands
 * @arg: str
 */
void _cd(char *arg)
{
	int cd = 0;

	if (arg != NULL)
	{
		cd = chdir(arg);
		if (cd < 0)
		{
			error(arg, _strlen(arg), 0);
		}
	}
	else
	{
		obt_dir();
	}
}
/**
 * _strcom - Struct to handle the built-ins commands
 * @str_1: input command to handle
 * @str_2: function pointer to execute the command
 * Return: 0 is ok
 */
int _strcom(char *str_1, char *str_2)
{
	int index = 0;

	for (; str_1[index] != '\0' && str_2[index] != '\0'; index++)
	{
		if (str_1[index] != str_2[index])
			return (-1);
	}
	return (0);
}
