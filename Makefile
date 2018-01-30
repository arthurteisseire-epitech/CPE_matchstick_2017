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
SRC     =	$(DSRC)main.c \
		$(DSRC)get_next_line.c \
		$(DSRC)print_extrem_line.c \
		$(DSRC)create_map.c \
		$(DSRC)print_map.c \
		$(DSRC)free_map.c
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
