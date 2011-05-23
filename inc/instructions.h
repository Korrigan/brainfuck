/*
** instructions.h for brainfuck in /home/rosins_m/projets/brainfuck
** 
** Made by matthieu rosinski
** Login   <rosins_m@epitech.net>
** 
** Started on  Mon May 23 22:40:12 2011 matthieu rosinski
** Last update Mon May 23 22:40:12 2011 matthieu rosinski
*/

#ifndef		INSTRUCTIONS_H_
# define	INSTRUCTIONS_H_

# ifndef	BRAINFUCK_H_
#  error	"Missing header: brainfuck.h"
# endif

# define	T_HANDLER_SZ	(sizeof(g_handler) / sizeof(g_handler[0]))

int		inc(struct s_bf *vm);
int		dec(struct s_bf *vm);
int		p_inc(struct s_bf *vm);
int		p_dec(struct s_bf *vm);
int		rd(struct s_bf *vm);
int		wr(struct s_bf *vm);
int		loop(struct s_bf *vm);

#endif	/*	!INSTRUCTIONS_H_ */
