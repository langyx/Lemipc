/*
** init_player.c for lemipc in /home/yannis/tek2/rendu/PSU_2016_lemipc
** 
** Made by yannis
** Login   <yannis.lang@epitech.eu>
** 
** Started on  Mon Mar 20 15:11:17 2017 yannis
** Last update Thu Mar 23 11:48:37 2017 yannis
*/

#include "lemipc.h"

struct s_case	*init_map(struct s_case *n_map)
{
  int		x;
  int		y;
  int		curr;

  x = 0;
  curr = 0;
  while (x < HEIGHT)
    {
      y = 0;
      while (y < WIDTH)
	{
	  n_map[curr].nteam = 0;
	  y += 1;
	  curr += 1;
        }
      x += 1;
    }
  return (n_map);
}

void	init_first_player(t_ipc *ipc, int idteam)
{
  struct s_case	*map;
  int		curr_pos;

  ipc->shm_id = shmget(ipc->key, (sizeof(struct s_case *)) * SIZE,
		       SHM_R | SHM_W | IPC_CREAT);
  ipc->sem_id = semget(ipc->key, 1, SHM_R | SHM_W | IPC_CREAT);
  ipc->msgq_id = msgget(ipc->key, SHM_R | SHM_W | IPC_CREAT);
  semctl(ipc->sem_id, 0, SETVAL, 1);
  map = shmat(ipc->shm_id, 0, 0);
  map = init_map(map);
  curr_pos = create_player(map, ipc, idteam);
   if (fork() == 0)
     create_display(map, ipc);
   else
     {
       player_brain(map, curr_pos, ipc);
       shmdt(map);
     }
}

void	init_other_players(t_ipc *ipc, int idteam)
{
  struct s_case *map;
  int		curr_pos;

  ipc->sem_id = semget(ipc->key, 1, SHM_R | SHM_W);
  ipc->msgq_id = msgget(ipc->key, SHM_R | SHM_W);
  map = shmat(ipc->shm_id, NULL, SHM_R | SHM_W);
  curr_pos = create_player(map, ipc, idteam);
  player_brain(map, curr_pos, ipc);
  shmdt(map);
}

void     init_ipc(char **av, t_ipc *ipc)
{
  ipc->key = ftok(av[1], 0);
  ipc->shm_id = shmget(ipc->key,
		       (sizeof(struct s_case *)) *
		       SIZE, SHM_R | SHM_W);
  if (ipc->shm_id == -1)
    init_first_player(ipc, atoi(av[2]));
  else
    init_other_players(ipc, atoi(av[2]));
}
