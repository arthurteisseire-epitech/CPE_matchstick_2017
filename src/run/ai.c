/*
** EPITECH PROJECT, 2017
** File Name : ai.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "matchstick.h"

int ai_output(map_t *map)
{
	int line;
	int sticks;

	if (set_line_and_sticks(map, &line, &sticks) == -1) {
		line = 0;
		line = next_valid_line(map, line);
		sticks = 1;
	}
	print_ai_info(sticks, line + 1);
	remove_sticks(map, sticks, line + 1);
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

int set_line_and_sticks(map_t *map, int *line, int *sticks)
{
	*sticks = 1;

	while (*sticks < map->max_sticks + 1 && *sticks < map->len_line - 3) {
		if ((*line = check_each_line(map, *sticks)) != -1)
			return (0);
		(*sticks)++;
	}
	return (-1);
}

int check_each_line(map_t *map, int sticks)
{
	int line = 0;

	while (line < map->nb_row) {
		if (good_move(map, line, sticks) == 0)
			return (line);
		line++;
	}
	return (-1);
}

int good_move(map_t *map, int line, int sticks)
{
	int i = 0;
	int binary = 0;

	while (i < map->nb_row) {
		if (i == line && map->line[i].nb_sticks - sticks >= 0)
			binary ^= map->line[i].nb_sticks - sticks;
		else
			binary ^= map->line[i].nb_sticks;
		i++;
	}
	if (binary == 0)
		return (0);
	return (-1);
}

int next_valid_line(map_t *map, int line)
{
	while (line < map->nb_row) {
		if (map->line[line].nb_sticks > 0)
			return (line);
		line++;
	}
	return (-1);
}
