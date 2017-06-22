/*
** create_display.c for create in /home/yannis/tek2/rendu/PSU_2016_lemipc
** 
** Made by yannis
** Login   <yannis.lang@epitech.eu>
** 
** Started on  Mon Mar 20 17:41:47 2017 yannis
** Last update Mon Mar 27 12:03:53 2017 Manu
*/

#include "lemipc.h"

int	can_play_game(struct s_case *map)
{
  int	i;
  int	temp_id;

  i = 0;
  temp_id = map[i].nteam;
  while (i < WIDTH * HEIGHT)
    {
      if (map[i].nteam != EMPTY
	  && temp_id == EMPTY)
	{
	  temp_id = map[i].nteam;
	}
      else if (temp_id != EMPTY
	       && temp_id != map[i].nteam
	       && map[i].nteam != EMPTY)
	{
	  return (0);
	}
      i += 1;
    }
  return (temp_id);
}

void	core_display(struct s_case *map, t_ipc *ipc)
{
  int	i;

  i = 0;
  unlock(ipc->sem_id);
  lock(ipc->sem_id);
  while (i < WIDTH * HEIGHT)
    {
      if (map[i].nteam != EMPTY)
	printf("%d", map[i].nteam);
      else
	printf(" ");
      i += 1;
      if (!(i % WIDTH))
	printf("\n");
    }
  unlock(ipc->sem_id);
  usleep(10000);
}

void	kill_all(t_ipc *ipc)
{
  semctl(ipc->sem_id, 1, IPC_RMID);
  msgctl(ipc->msgq_id, IPC_RMID, NULL);
  shmctl(ipc->shm_id, IPC_RMID, NULL);
}

void	create_display(struct s_case *map, t_ipc *ipc)
{
  int	teamid;

  while (can_play_game(map) != 0)
    sleep(1);
  while ((teamid = can_play_game(map)) == 0)
    {
      core_display(map, ipc);
      system("clear");
    }
  core_display(map, ipc);
  printf("Team %d à gagné\n", teamid);
  map[0].nteam = ERROR;
  shmdt(map);
  kill_all(ipc);
  kill(getpid(), SIGQUIT);
}
