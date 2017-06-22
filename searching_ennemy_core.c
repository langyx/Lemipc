/*
** searching_ennemy_core.c for core in /home/yannis/tek2/rendu/PSU_2016_lemipc
** 
** Made by yannis
** Login   <yannis.lang@epitech.eu>
** 
** Started on  Mon Mar 20 19:26:35 2017 yannis
** Last update Sat Apr  1 01:29:16 2017 Manu
*/

#include "lemipc.h"

int	get_true_new_pos(int curr, int new_p)
{
  if (get_y(curr) > get_y(new_p))
    return (curr - HEIGHT);
  if (get_y(curr) < get_y(new_p))
    return (curr + HEIGHT);
  if (get_x(curr) > get_x(new_p))
    return (curr - 1);
  return (curr + 1);
}

void		push_msg(struct s_case *map,
			 int new_index, t_ipc *ipc)
{
  t_buffmsg	buffmsg;

  buffmsg.mtype = map[new_index].nteam;
  buffmsg.pos = new_index;
  buffmsg.mtext[0] = 'a';
  buffmsg.mtext[1] = '\0';
  msgsnd(ipc->msgq_id,
	 &buffmsg,
	 sizeof(t_buffmsg),
	 buffmsg.mtype | IPC_NOWAIT);
}

int	get_distance(int curr, int new_p)
{
  return (sqrt(pow(get_x(new_p) - get_x(curr), 2)
	       + pow(get_y(new_p) - get_y(curr), 2)));
}

int	get_random_pos(struct s_case *map, int curr)
{
  int	curr_x;
  int	curr_y;
  int	choice;

  curr_x = get_x(curr);
  curr_y = get_y(curr);
  choice = rand() % 4;
  if (choice == 0
      && curr_y > 0
      && map[curr - HEIGHT].nteam == EMPTY)
    return (curr - HEIGHT);
  if (choice == 1
      && curr_y < SIZE
      && map[curr + HEIGHT].nteam == EMPTY)
    return (curr + HEIGHT);
  if (choice == 2
      && curr_x < SIZE
      && map[curr + 1].nteam == EMPTY)
    return (curr + 1);
  if (choice == 3
      && curr_x > 0
      && map[curr - 1].nteam == EMPTY)
    return (curr - 1);
  return (curr);
}
