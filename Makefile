##
## Makefile for push_swap in /home/sebastien/travaux/push_swap
## 
## Made by Sebastien Chapuis
## Login   <sebastien@epitech.net>
## 
## Started on  Sat Dec 21 20:05:03 2013 Sebastien Chapuis
## Last update Sun Jan  5 22:03:22 2014 Sebastien Chapuis
##

SRC	= main.c \
	  list_linked.c \
	  swap.c \
	  utils.c \
	  disp.c

NAME	= push_swap

OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
