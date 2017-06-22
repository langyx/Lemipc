/*
** alive.c for alive in /home/yannis/tek2/rendu/PSU_2016_lemipc
** 
** Made by yannis
** Login   <yannis.lang@epitech.eu>
** 
** Started on  Mon Mar 20 20:17:55 2017 yannis
** Last update Wed Mar 22 14:02:01 2017 Manu
*/

#include "lemipc.h"

int	will_him_die(int *boxcase, int teamid)
{
  int	i;
  int	j;

  i = 0;
  while (i < 8)
    {
      if (boxcase[i] != teamid
	  && boxcase[i] != 0)
	{
	  j = 0;
	  while (j < 8)
	    {
	      if (j != i && boxcase[j] == boxcase[i])
		return (0);
	      j += 1;
	    }
	}
      i += 1;
    }
  return (1);
}

int	is_him_alive(struct s_case *map, int curr_pos)
{
  int	boxcases[8];
  int	i;

  BOXTAB;
  if (will_him_die(boxcases, map[curr_pos].nteam) == 0)
    {
      map[curr_pos].nteam = 0;
      return (0);
    }
  return (1);
}
