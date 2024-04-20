##
## EPITECH PROJECT, 2024
## B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
## File description:
## Makefile
##

NAME	=	mysh

SRC 	=	$(wildcard minishell/*.c)
SRC += $(wildcard func/*.c)

OBJ	=	$(SRC:.c=.o)

CPPFLAGS=	-I./include/

all	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f *#
		rm -f minishell/*#
		rm -f include/*#
		rm -f *~
		rm -f minishell/*~
		rm -f include/*~

re	:	fclean all
