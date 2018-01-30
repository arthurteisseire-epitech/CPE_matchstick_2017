/*
** EPITECH PROJECT, 2017
** File Name : matchstick.h
** File description:
** by Arthur Teisseire
*/

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

typedef struct line {
	char *str;
	char *last_stick;
	int nb_stick;
} line_t;

typedef struct map {
	line_t *line;
	int nb_row;
	int len_line;
} map_t;

void print_extrem_line(int nb_row);
int init_map(map_t *map);
int set_map_line(map_t *map, int i);

#endif
