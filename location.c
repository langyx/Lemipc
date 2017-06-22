/*
** location.c for lemipc in /home/yannis/tek2/rendu/PSU_2016_lemipc
** 
** Made by yannis
** Login   <yannis.lang@epitech.eu>
** 
** Started on  Mon Mar 20 16:05:11 2017 yannis
** Last update Mon Mar 20 16:23:00 2017 yannis
*/

#include "lemipc.h"

int	 get_y(int pos)
{
  int	i;

  i = 0;
  while (pos > HEIGHT)
    {
      pos -= HEIGHT;
      i += 1;
    }
  return (i);
}

int	get_x(int pos)
{
  while (pos > HEIGHT)
    pos -= HEIGHT;
  pos -= 1;
  return (pos);
}
