##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
DSRC	=	$(realpath src)/
INC	=	$(realpath include)
DLIB	=	$(realpath lib/my)/
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)
DINIT	=	$(DSRC)init/
DESTROY	=	$(DSRC)destroy/
DINIT	=	$(DSRC)init/
DPRINT	=	$(DSRC)print_map/
DERR	=	$(DSRC)error_handling/
DRUN	=	$(DSRC)run/
SRC     =	$(DSRC)main.c \
		$(DSRC)get_next_line.c \
		$(DINIT)init_map.c \
		$(DPRINT)print_extrem_line.c \
		$(DPRINT)print_map.c \
		$(DESTROY)free_map.c \
		$(DERR)check_args.c \
		$(DERR)input_errors.c \
		$(DRUN)run_game.c \
		$(DRUN)player_io.c \
		$(DRUN)ai.c
CFLAGS	+=	-Wall -W -Wextra -I$(INC) -ggdb3
OBJ	=	$(SRC:.c=.o)
NAME	=	matchstick

all: $(NAME)

$(NAME):	$(OBJ)
	make -C $(DLIB)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean:
	make clean -C $(DLIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(DLIB)
	rm -f $(NAME)

re: fclean all

test_run: all
	make test_run -C tests
