##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
ROOT	=	$(realpath ..)/
DSRC_UT	=	$(realpath .)/
DLIB	=	$(ROOT)lib/my/
DSRC	=	$(ROOT)src/
INC	=	$(ROOT)include/
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)

SRC_UT	=	$(DSRC_UT)test_lines.c
SRC	=	$(DSRC)get_next_line.c

CFLAGS	=	-Wall -W -Wextra --coverage -I$(INC)
LDFLAGS	=	-lcriterion -lgcov
OBJ	=	$(SRC_UT:.c=.o) $(SRC:.c=.o)
NAME	=	units

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test_run: all
	./$(NAME)
