/*
** movement_player.c for move in /home/yannis/tek2/rendu/PSU_2016_lemipc
** 
** Made by yannis
** Login   <yannis.lang@epitech.eu>
** 
** Started on  Mon Mar 20 18:53:07 2017 yannis
** Last update Wed Mar 22 14:04:43 2017 Manu
*/

#include "lemipc.h"

int	search_ennemy(struct s_case *map, int curr_pos, t_ipc *ipc)
{
  int	x;
  int	temp_distance;
  int	temp_calcul;
  int	temp_index;

  x = 0;
  temp_distance = 0;
  temp_index = 0;
  while (x < SIZE)
    {
      if (map[x].nteam != EMPTY
	  && map[x].nteam != map[curr_pos].nteam)
	{
	  temp_calcul = get_distance(curr_pos, x);
	  if (temp_distance < temp_calcul ||
	      temp_distance == 0)
	    {
	      temp_distance = temp_calcul;
	      temp_index = x;
	    }
	}
      x += 1;
    }
  push_msg(map, temp_index, ipc);
  return (get_true_new_pos(curr_pos, temp_index));
}

int	move_player_core(struct s_case *map, int curr_pos,
			 t_ipc *ipc)
{
  int		msg_recev;
  t_buffmsg	buffmsg;
  int		new_pos;
  int		id_team;

  id_team = map[curr_pos].nteam;
  msg_recev = msgrcv(ipc->msgq_id, &buffmsg,
		     sizeof(t_buffmsg), map[curr_pos].nteam,
		     IPC_NOWAIT);
  if (msg_recev == ERROR ||
      buffmsg.mtype == map[curr_pos].nteam ||
      buffmsg.pos == curr_pos)
    new_pos = search_ennemy(map, curr_pos, ipc);
  else
    new_pos = get_true_new_pos(curr_pos, buffmsg.pos);
  if (map[new_pos].nteam != EMPTY)
    new_pos = get_random_pos(map, curr_pos);
  map[curr_pos].nteam = EMPTY;
  map[new_pos].nteam = id_team;
  return (new_pos);
}
