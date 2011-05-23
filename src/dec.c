/*
** dec.c for brainfuck in /home/rosins_m/projets/brainfuck
** 
** Made by matthieu rosinski
** Login   <rosins_m@epitech.net>
** 
** Started on  Mon May 23 22:50:06 2011 matthieu rosinski
** Last update Mon May 23 22:50:06 2011 matthieu rosinski
*/

#include		"brainfuck.h"

int			dec(struct s_bf *vm)
{
  (vm->mem[vm->p])--;
  return (0);
}
