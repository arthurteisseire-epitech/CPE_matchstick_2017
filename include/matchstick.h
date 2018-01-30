/*
** EPITECH PROJECT, 2017
** File Name : matchstick.h
** File description:
** by Arthur Teisseire
*/

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

#include <stdlib.h>

typedef struct line {
	char *str;
	char *last_stick;
	int nb_sticks;
} line_t;

typedef struct map {
	line_t *line;
	int nb_row;
	int len_line;
	int max_sticks;
	int nb_sticks;
	int line_in;
	int stick_in;
} map_t;

void print_extrem_line(int nb_row);
int init_map(map_t *map, char **args);
int set_map_line(map_t *map, int i);
void put_sticks(line_t *line, int *j);
void put_spaces(char *str, int *j, int nb_spaces);
void print_map(map_t *map);
void free_map(map_t *map);
int count_sticks(map_t *map);
int run_game(map_t *map);
int remove_sticks(map_t *map);
int player_io(map_t *map);
int input(map_t *map, int (*f)(map_t *map, char *input), char *ouput);
int stick_errors(map_t *map, char *input);
int line_errors(map_t *map, char *input);

#endif
