/*
** create_player.c for lemipc in /home/yannis/tek2/rendu/PSU_2016_lemipc
** 
** Made by yannis
** Login   <yannis.lang@epitech.eu>
** 
** Started on  Mon Mar 20 16:37:28 2017 yannis
** Last update Mon Mar 27 12:02:31 2017 Manu
*/

#include "lemipc.h"

int             lock(int sem_id)
{
  struct sembuf sembuff;

  sembuff.sem_num = 0;
  sembuff.sem_flg = 0;
  sembuff.sem_op = -1;
  if (semop(sem_id, &sembuff, 1) == -1)
    unlock(sem_id);
  return (0);
}

void            unlock(int sem_id)
{
  struct sembuf sembuff;

  sembuff.sem_num = 0;
  sembuff.sem_flg = 0;
  sembuff.sem_op = 1;
  semop(sem_id, &sembuff, 1);
}

int	is_very_full(struct s_case *map)
{
  int	i;
  int	new_pos;

  i = 0;
  while (i < SIZE)
    {
      if (map[i].nteam == 0)
	{
	  new_pos = rand() % (SIZE - 1);
	  while (map[new_pos].nteam != EMPTY)
	    new_pos = rand() % (SIZE - 1);
	  return new_pos;
	}
      i += 1;
    }
  return (-1);
}

int	create_player(struct s_case *map, t_ipc *ipc, int idteam)
{
  int	new_pos;

  lock(ipc->sem_id);
  new_pos = is_very_full(map);
  if (new_pos == -1)
    {
      unlock(ipc->sem_id);
      exit(0);
    }
  map[new_pos].nteam = idteam;
  unlock(ipc->sem_id);
  return (new_pos);
}
