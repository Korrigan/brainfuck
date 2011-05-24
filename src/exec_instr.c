/*
** exec_instr.c for brainfuck in /home/rosins_m/projets/brainfuck
** 
** Made by matthieu rosinski
** Login   <rosins_m@epitech.net>
** 
** Started on  Mon May 23 22:44:01 2011 matthieu rosinski
** Last update Mon May 23 22:44:01 2011 matthieu rosinski
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"brainfuck.h"
#include	"instructions.h"

static const struct {
  char		c;
  int		(*f)(struct s_bf *);
}		g_handler[] =
  {
    {'+', inc},
    {'-', dec},
    {'>', p_inc},
    {'<', p_dec},
    {'.', wr},
    {',', rd},
    {'[', loop}
  };

int		exec_instr(struct s_bf *vm, char instr)
{
  for (size_t i = 0; i < T_HANDLER_SZ; i++)
   if (instr == g_handler[i].c)
     return (g_handler[i].f(vm));
  return (0);
}
