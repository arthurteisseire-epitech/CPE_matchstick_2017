/*
** EPITECH PROJECT, 2017
** File Name : ia.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "matchstick.h"

int ai_output(map_t *map)
{
	int line = get_ai_line(map);
	int sticks = get_ai_sticks(map, line);

	my_putstr("\nAI's turn...\n");
	my_putstr("AI removed ");
	my_put_nbr(sticks);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putchar('\n');
	remove_sticks(map, sticks, line);
	return (0);
}

int get_ai_line(map_t *map)
{
	int line;
	int i = 0;
	int max = map->line[0].nb_sticks;

	while (i < map->nb_row) {
		if (map->line[i].nb_sticks > max) {
			max = map->line[i].nb_sticks;
			line = i;
		}
		i++;
	}
	return (line + 1);
}

int get_ai_sticks(map_t *map, int line)
{
	if (map->line[line - 1].nb_sticks > map->max_sticks)
		return (map->max_sticks);
	else if (map->line[line - 1].nb_sticks == 1)
		return (1);
	else
		return (map->line[line - 1].nb_sticks - 1);
}
