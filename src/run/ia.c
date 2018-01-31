/*
** EPITECH PROJECT, 2017
** File Name : ia.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "matchstick.h"

int ia_output(map_t *map)
{
	time_t ref_time = time(NULL);
	int line = 0;
	int sticks = 0;

	my_putstr("\nAI's turn...\n");
	while (time(NULL) < ref_time + 2) {}
	my_putstr("AI removed ");
	my_put_nbr(sticks);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putchar('\n');
	return (0);
}
