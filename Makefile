##
## Makefile for push_swap in /home/sebastien/travaux/push_swap
## 
## Made by Sebastien Chapuis
## Login   <sebastien@epitech.net>
## 
## Started on  Sat Dec 21 20:05:03 2013 Sebastien Chapuis
## Last update Sun Dec 22 11:36:56 2013 Sebastien Chapuis
##

SRC	= main.c \
	  list_linked.c \
	  swap.c \
	  utils.c \
	  disp.c

NAME	= push_swap

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "\033[32m[build]" | tr -d '\n'
	gcc $(OBJ) -o $(NAME)
	@echo -e "\033[0m" | tr -d '\n'

clean:
	@echo -e "\033[31m[clean] " | tr -d '\n'
	rm -f $(OBJ)
	@echo -e "\033[0m" | tr -d '\n'

fclean:	clean
	@echo -e "\033[31m[fclean] " | tr -d '\n'
	rm -f $(NAME)
	@echo -e "\033[0m" | tr -d '\n'

re:	fclean all
