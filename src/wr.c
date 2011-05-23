/*
** wr.c for brainfuck in /home/rosins_m/projets/brainfuck
** 
** Made by matthieu rosinski
** Login   <rosins_m@epitech.net>
** 
** Started on  Mon May 23 22:52:18 2011 matthieu rosinski
** Last update Mon May 23 22:52:18 2011 matthieu rosinski
*/

#include	<unistd.h>

#include	"brainfuck.h"

int		wr(struct s_bf *vm)
{
  if (write(STDOUT_FILENO, vm->mem + vm->p, 1) != 1)
    return (1);
  return (0);
}
