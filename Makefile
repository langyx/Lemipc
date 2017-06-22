##
## Makefile for  in /home/manu/TEK2/PSU_2016_lemipc
## 
## Made by Manu
## Login   <vallen_e@epitech.net>
## 
## Started on  Mon Mar 20 11:00:13 2017 Manu
## Last update Tue Mar 21 04:01:52 2017 yannis
##

SRC	= main.c \
	  create_display.c \
	  create_player.c \
	  init_player.c \
	  location.c \
	  alive.c \
	  searching_ennemy_core.c \
	  movement_player.c

NAME	= lemipc

CFLAGS  = -lm -W -Wall -Wextra #-Werror

CC	= cc -g3

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
