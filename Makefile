##
## Makefile for brainfuck in /home/rosins_m/projets/brainfuck
## 
## Made by matthieu rosinski
## Login   <rosins_m@epitech.net>
## 
## Started on  Mon May 23 22:17:25 2011 matthieu rosinski
## Last update Mon May 23 22:17:25 2011 matthieu rosinski
##

NAME=		bf

SRCF=		main.c \
		prompt.c \
		exec_instr.c \
		inc.c \
		dec.c \
		p_inc.c \
		p_dec.c \
		wr.c \
		rd.c \
		loop.c

SRC=		$(addprefix src/, $(SRCF))
OBJ=		$(SRC:.c=.o)

CC=		gcc
RM=		@rm -fv

CFLAGS+=	-W -Wall -Wextra -std=c99 -g3
CFLAGS+=	-Iinc -D_GNU_SOURCE

$(NAME):	$(OBJ)
		$(CC) -o $@ $^

all:		$(NAME)

%.o:		%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

mrproper:	clean
		$(RM) $(NAME)

re:		mrproper all

.PHONY:		all clean mrproper re
