/*
** EPITECH PROJECT, 2017
** File Name : my_str_isnum.c
** File description:
** by Arthur Teisseire
*/

int my_str_isnum(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
