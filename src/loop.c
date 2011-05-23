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

#include	"brainfuck.h"

static int	exec_loop(struct s_bf *vm)
{
  do
    for (size_t i = 0; vm->loop[i]; i++)
      if (exec_instr(vm, vm->loop[i]))
	return (1);
  while (vm->mem[vm->p]);
  return (0);
}

int		loop(struct s_bf *vm)
{
  char		instr;
  int		rd;

  if (!(vm->loop = calloc(1, sizeof(char))))
    return (1);
  while (((rd = read(vm->fd, &instr, 1)) == 1)
	 && instr != ']')
    {
      int len = strlen(vm->loop);
      if (!(vm->loop = realloc(vm->loop, len + 2)))
	return (1);
      vm->loop[len] = instr;
      vm->loop[len + 1] = 0;
    }
  if (rd == -1)
    return (1);
  exec_loop(vm);
  free(vm->loop);
  vm->loop = NULL;
  return (0);
}
