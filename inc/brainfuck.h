/*
** brainfuck.h for brainfuck in /home/rosins_m/projets/brainfuck
** 
** Made by matthieu rosinski
** Login   <rosins_m@epitech.net>
** 
** Started on  Mon May 23 22:27:19 2011 matthieu rosinski
** Last update Mon May 23 22:27:19 2011 matthieu rosinski
*/

#ifndef		BRAINFUCK_H_
# define	BRAINFUCK_H_

# define	MEM_SIZE		1000000
# define	MAX_RECURSION_DEPTH	4096

struct		s_bf
{
  int		fd;
  unsigned	p;
  int		*mem;
};

int		exec_instr(struct s_bf *vm, char instr);

#endif	/*	!BRAINFUCK_H_ */
