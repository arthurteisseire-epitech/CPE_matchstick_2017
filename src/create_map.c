/*
** EPITECH PROJECT, 2017
** File Name : create_map.c
** File description:
** by Arthur Teisseire
*/

#include "matchstick.h"

int init_map(map_t *map)
{
	int i = 0;

	map->line = malloc(sizeof(line_t) * map->nb_row);
	if (map->line == NULL)
		return (-1);
	while (i < map->nb_row) {
		map->line[i].nb_sticks = 2 * i + 1;
		set_map_line(map, i);
		i++;
	}
	return (0);
}

int set_map_line(map_t *map, int i)
{
	int j = 0;
	int nb_spaces = map->nb_row - (i + 1);

	map->line[i].str = malloc(sizeof(char) * (map->len_line + 1));
	if (map->line[i].str == NULL)
		return (-1);
	map->line[i].str[map->len_line] = '\0';
	map->line[i].str[0] = '*';
	j++;
	put_spaces(map->line[i].str, &j, nb_spaces);
	put_sticks(&(map->line[i]), &j);
	put_spaces(map->line[i].str, &j, nb_spaces);
	map->line[i].str[j] = '*';
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
