/*
** prompt.c for  in /home/rosins_m/projets/brainfuck
** 
** Made by matthieu rosinski
** Login   <rosins_m@epitech.net>
** 
** Started on  Tue May 24 11:55:19 2011 matthieu rosinski
** Last update Tue May 24 11:55:19 2011 matthieu rosinski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<errno.h>
#include	<unistd.h>

#include	"brainfuck.h"

static void	aff_prompt(int fd, const char *req)
{ 
  if (fd == STDIN_FILENO)
    {
      if (req)
	printf("%s? ", req);
      else
	printf("bf> ");
      fflush(stdout);
    }
}

char		prompt(const struct s_bf *vm, const char *req)
{
  static char	*buffer = NULL;
  static size_t	pos = 0;
  size_t	len;
  int		rd = 0;

  if (buffer && (!buffer[pos] || buffer[pos] == '\n'))
    {
      pos = 0;
      free(buffer);
      buffer = NULL;
    }
  else if (!buffer)
    {
      len = 0;
      aff_prompt(vm->fd, req);
      while ((buffer = realloc(buffer, len + 2))
	     && ((rd = read(vm->fd, buffer + len, 1)) == 1))
	{
	  buffer[++len] = 0;
	  if (buffer[len - 1] == '\n')
	    break;
	}
    }
  if (!buffer || rd == -1)
    return (-1);
  return (buffer[pos++]);
}
