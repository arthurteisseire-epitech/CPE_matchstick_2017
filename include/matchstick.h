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

void print_extrem_line(int nb_row);

#endif
