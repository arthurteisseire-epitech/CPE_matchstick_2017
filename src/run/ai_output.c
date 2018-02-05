/*
** EPITECH PROJECT, 2017
** File Name : ai_output.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "matchstick.h"

int ai_output(map_t *map)
{
	int line;
	int sticks;

	if (can_win(map, &line, &sticks) == 0) {
	} else if (set_line_and_sticks(map, &line, &sticks) == -1) {
		line = next_valid_line(map, 0);
		sticks = 1;
	}
	print_ai_info(sticks, line);
	remove_sticks(map, sticks, line);
	return (0);
}

void print_ai_info(int sticks, int line)
{
	my_putstr("\nAI's turn...\n");
	my_putstr("AI removed ");
	my_put_nbr(sticks);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putchar('\n');
}
