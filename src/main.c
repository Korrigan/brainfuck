/*
** main.c for brainfuck in /home/rosins_m/projets/brainfuck
** 
** Made by matthieu rosinski
** Login   <rosins_m@epitech.net>
** 
** Started on  Mon May 23 22:24:10 2011 matthieu rosinski
** Last update Mon May 23 22:24:10 2011 matthieu rosinski
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<errno.h>

#include	"brainfuck.h"

static int	get_fd(int ac, char **av, struct s_bf *vm)
{
  if (ac == 1)
    return (0);
  if ((vm->fd = open(av[1], O_RDONLY)) == -1)
    return (1);
  return (0);
}

int		main(int ac, char **av)
{
  char		instr;
  struct s_bf	vm;

  memset(&vm, 0, sizeof(vm));
  if (!(vm.mem = (int *)calloc(MEM_SIZE, sizeof(int)))
      || get_fd(ac, av, &vm))
    goto err;
  while ((instr = prompt(&vm, NULL)) != -1)
    if (exec_instr(&vm, instr))
      goto err;
  if ((instr == -1)
      || (vm.fd && close(vm.fd) == -1))
    goto err;
  free(vm.mem);
  return (EXIT_SUCCESS);
 err:
  perror(program_invocation_short_name);
  return (EXIT_FAILURE);
}
