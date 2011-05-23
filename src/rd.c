/*
** rd.c for brainfuck in /home/rosins_m/projets/brainfuck
** 
** Made by matthieu rosinski
** Login   <rosins_m@epitech.net>
** 
** Started on  Mon May 23 22:54:27 2011 matthieu rosinski
** Last update Mon May 23 22:54:27 2011 matthieu rosinski
*/

#include	<unistd.h>

#include	"brainfuck.h"

int		rd(struct s_bf *vm)
{
  if (read(STDIN_FILENO, vm->mem + vm->p, 1) != 1)
    return (1);
  return (0);
}
