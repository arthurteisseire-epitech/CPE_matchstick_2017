/*
** EPITECH PROJECT, 2017
** File Name : run_game.c
** File description:
** by Arthur Teisseire
*/

#include "matchstick.h"
#include "get_next_line.h"
#include "my.h"

int run_game(map_t *map)
{
	while (map->nb_sticks > 0) {
		print_map(map);
		player_io(map);
		if (remove_sticks(map) == 0) {
			map->nb_sticks -= map->stick_in;
			map->line[map->line_in - 1].nb_sticks -= map->stick_in;
		}
	}
	my_putstr("You Won\n");
	return (0);
}

int remove_sticks(map_t *map)
{
	int i = 0;

	while (i < map->stick_in) {
		map->line[map->line_in - 1].last_stick[0] = ' ';
		map->line[map->line_in - 1].last_stick -= 1;
		i++;
	}
	return (0);
}
