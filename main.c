/*
** main.c for  in /home/manu/TEK2/PSU_2016_lemipc
** 
** Made by Manu
** Login   <vallen_e@epitech.net>
** 
** Started on  Mon Mar 20 14:38:21 2017 Manu
** Last update Mon Mar 27 12:02:44 2017 Manu
*/

#include "lemipc.h"

void	player_brain(struct s_case *map, int curr_pos, t_ipc *ipc)
{
  int	alive;

  alive = 1;
  while (alive)
    {
      if (map[0].nteam == ERROR)
	break;
      lock(ipc->sem_id);
      curr_pos = move_player_core(map, curr_pos, ipc);
      alive = is_him_alive(map, curr_pos);
      unlock(ipc->sem_id);
      usleep(200000);
    }
}

int	main(int ac, char **av)
{
  t_ipc ipc;

  srand(time(NULL));
  if (ac == 3)
    init_ipc(av, &ipc);
  else
    printf("Usage : ./lemipc [PATH] [TEAM_NUMB]\n");
  return (0);
}
