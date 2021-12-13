#include "main.h"
/**
 * path - a function that handles path.
 * @array: an array of string pointers.
 * @cont: the loop counter from getline
 * @ex_status: control of the exit
 * Return: return concatenated string; otherwise: NULL.
 */
int path(char **array, int cont, int *ex_status)
{
	char *path_original = _getenv("PATH"), *path_copy = stringdup(path_original);
	char *token = NULL, *cats = NULL;
	pid_t c_pid = 0;
	int cort = 0;
	
	if (_which(array[0]) == 0)
	{
		_wh(&array, &ex_status[0], &cont, &c_pid);
		free(path_copy);
		return (ex_status[0]);
	}
	else
	{
		
		cort = _strtok(path_copy, 58, cort, &token);
		while (token != NULL)
		{
			printf("--------------------------------------\n");
			printf("--------------%d\n", _strlen(array[0]));
			str_concat(token, array[0], 1, &cats);
			if (_which(cats) == 0)
			{
				printf("entro al if del paht y  en el token es %s\n", token);
				if (access(cats, X_OK) == 0)
				{
					printf("entro al if acces-----------\n");
					array[0] = cats;
					ex_status[0] = exec(c_pid, array, cont, cats);
					printf("la devolucin de ex_es--------- %d", ex_status[0]);
					free(token);
					free(cats);
					free(path_copy);
					return (ex_status[0]);
				}
				else
				{
					printf("entro al else------------\n");
					free(token);
					free(path_copy);
					free(cats);
					error(array[0], cont, 1);
					return (2);
				}
			}
			free(token);
			token = NULL;
			cort = _strtok(path_copy, 58, cort, &token);
			free(cats);
			cats = NULL;
		}
		free(path_copy);
		free(token);
		free(cats);
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
