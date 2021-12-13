#include "main.h"

/**
 * toksize - number of tokens from getline
 * @str: string to count number of tokens
 * Return: number of tokens
 */

int toksize(char *str)
{
	int tok_size = 0, i = 0;

	if (!str)
	{
		write(STDIN_FILENO, '\0', 1);
		return (-1);
	}
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
			str[i] = ' ';
		if (str[i + 1] == '\t')
			str[i + 1] = ' ';
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			tok_size++;
		i++;
	}
	return (tok_size);
}

/**
 * tokenize - function to get tokens from string
 * and store in an array
 * @str: string to tokenize
 * Return: array
 */
void tokenize(char *str, char ***array)
{
	char *token = NULL;
	int i = 0, words = 0, cort = 0, f = 0;

	words = toksize(str);
	if (!words)
		return;
	words++;
	printf("el tamanio del array va a ser de %d */*/*/*/*/\n", words);
	array[0] = malloc(sizeof(char *) * words);
	if (!array[0])
		return;
	cort = _strtok(str, 10, cort, &token);
	printf("al salir de _strtok tokem contiene %s-------------", token);
	if (str[cort])
	{
		array[0][i] = token;
		
		while (str[cort] && cort != -1)
		{
			i++;
			printf("---------------entro---------yok\n");
			cort = _strtok(str, 10, cort, &token);
			array[0][i] = malloc(sizeof(char *) * (_strlen(token) + 1));
			for (;token[f]; f++)
				array[0][i][f] = token[f];
			array[0][i][f] = '\0';
			f = 0;
			free(token);	
			printf("sssssssssss***/*/*/*/---------------- %d\n", cort);
			
		}
		i++;
		printf("array em 1*-*-*-*-*-*-*-*-*-*%d\n", i);
		array[0][i] = NULL;
	}
	else
	{
		array[0][0] = malloc(sizeof(char *) * (_strlen(token) + 1));
		for (;token[f]; f++)
			array[0][0][f] = token[f];
		array[0][0][f] = '\0';
		free(token);
		printf("*****************salio**************\n");
		printf("tamaño de token de tokenize es de */*/*/*/*/*/*/*/*/*/*/*/*/%lu\n", sizeof(token));
		array[0][1] = NULL;
		printf("*****************str_array**************%s\n", array[0][0]);
		
	}
}
