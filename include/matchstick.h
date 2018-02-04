/*
** EPITECH PROJECT, 2017
** File Name : matchstick.h
** File description:
** by Arthur Teisseire
*/

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

#include <stdlib.h>
#include <time.h>

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
int remove_sticks(map_t *map, int nb_sticks, int index_line);
int player_io(map_t *map);
int input(map_t *map, int (*f)(map_t *map, char *input), char *ouput);
int stick_errors(map_t *map, char *input);
int line_errors(map_t *map, char *input);
void print_player_info(map_t *map);
int ai_output(map_t *map);
int get_ai_line(map_t *map);
int get_ai_sticks(map_t *map, int line);
void print_ai_info(int sticks, int line);
int next_valid_line(map_t *map, int line);
int good_move(map_t *map, int line, int sticks);
int check_each_line(map_t *map, int sticks);
int set_line_and_sticks(map_t *map, int *line, int *sticks);
int can_win(map_t *map, int *line, int *sticks);
int all_empty_except_one(map_t *map);
int count_valid_line(map_t *map);
int set_nb_sticks(map_t *map, int line, int *sticks, int nb_valid);
int first_one_stick_line(map_t *map);
int set_for_last_line(map_t *map, int *line, int *sticks, int nb_valid);
int set_on_all_one_sticks(map_t *map, int *line, int *sticks, int nb_valid);

#endif
