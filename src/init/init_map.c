/*
** EPITECH PROJECT, 2017
** File Name : create_map.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "matchstick.h"

int init_map(map_t *map, char **args)
{
	int i = 0;

	map->nb_row = my_atoi(args[0]);
	map->max_sticks = my_atoi(args[1]);
	map->len_line = map->nb_row * 2 + 1;
	map->line = malloc(sizeof(line_t) * map->nb_row);
	if (map->line == NULL)
		return (-1);
	while (i < map->nb_row) {
		map->line[i].nb_sticks = 2 * i + 1;
		set_map_line(map, i);
		i++;
	}
	count_sticks(map);
	return (0);
}

int set_map_line(map_t *map, int i)
{
	int j = 0;
	int nb_spaces = map->nb_row - (i + 1);

	map->line[i].str = malloc(sizeof(char) * (map->len_line + 2));
	if (map->line[i].str == NULL)
		return (-1);
	map->line[i].str[map->len_line + 1] = '\0';
	map->line[i].str[0] = '*';
	j++;
	put_spaces(map->line[i].str, &j, nb_spaces);
	put_sticks(&(map->line[i]), &j);
	put_spaces(map->line[i].str, &j, nb_spaces);
	map->line[i].str[j] = '*';
	map->line[i].str[j + 1] = '\n';
	return (0);
}

void put_spaces(char *str, int *j, int nb_spaces)
{
	int i = 0;

	while (i < nb_spaces) {
		str[*j] = ' ';
		i++;
		(*j)++;
	}
}

void put_sticks(line_t *line, int *j)
{
	int i = 0;

	while (i < line->nb_sticks) {
		line->str[*j] = '|';
		i++;
		(*j)++;
	}
	line->last_stick = &(line->str[(*j) - 1]);
}

int count_sticks(map_t *map)
{
	int i = 0;

	map->nb_sticks = 0;
	while (i < map->nb_row) {
		map->nb_sticks += map->line[i].nb_sticks;
		i++;
	}
	return (0);
}
