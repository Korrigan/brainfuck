/*
** loop.c for brainfuck in /home/rosins_m/projets/brainfuck
** 
** Made by matthieu rosinski
** Login   <rosins_m@epitech.net>
** 
** Started on  Mon May 23 23:39:10 2011 matthieu rosinski
** Last update Mon May 23 23:39:10 2011 matthieu rosinski
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>

#include	"brainfuck.h"

static char	*append(char *str, char c)
{
  size_t	len = 0;

  if (str)
    len = strlen(str);
  if (!(str = realloc(str, len + 2)))
    return (NULL);
  str[len] = c;
  str[len + 1] = 0;
  return (str);
}

static int	exec_loop(struct s_bf *vm, char *loop)
{
  static int	depth = 0;

  if (++depth > MAX_RECURSION_DEPTH)
    {
      fprintf(stderr, "%s: %s", program_invocation_short_name,
	      "exec_loop(): max recursion depth reached");
      return (1);
    }
  do
    for (size_t i = 0; loop[i]; i++)
      if ((loop[i] == '[' && exec_loop(vm, loop + i))
	  || exec_instr(vm, loop[i]))
	return (1);
  while (vm->mem[vm->p]);
  depth--;
  return (0);
}

int		loop(struct s_bf *vm)
{
  char		*loop = NULL;
  char		instr;
  int		count = 1;

  while (count && (instr = prompt(vm, "]")) > 0)
    {
      if (!(loop = append(loop, instr)))
	return (1);
      if (instr == '[')
	count++;
      else if (instr == ']')
	count--;
    }
  if (instr == -1)
    return (1);
  exec_loop(vm, loop);
  free(loop);
  return (0);
}
