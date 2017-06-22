/*
** lemipc.h for  in /home/manu/TEK2/PSU_2016_lemipc
** 
** Made by Manu
** Login   <vallen_e@epitech.net>
** 
** Started on  Mon Mar 20 11:00:31 2017 Manu
** Last update Thu Mar 23 11:48:56 2017 yannis
*/

#ifndef LEMIPC_H__
# define LEMIPC_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <math.h>
#include <time.h>
#include <strings.h>
#include <signal.h>
#include <pthread.h>

#define HEIGHT 50
#define WIDTH 50
#define SIZE HEIGHT * WIDTH

#define EMPTY 0
#define ERROR -1

#define BOXTAB \
  boxcases[0] = ((i = curr_pos + 1) > SIZE) ? 0 : map[i].nteam;	\
  boxcases[1] = ((i = curr_pos + WIDTH + 1) > SIZE) ? 0 : map[i].nteam;	\
  boxcases[2] = ((i = curr_pos + WIDTH) > SIZE) ? 0 : map[i].nteam; \
  boxcases[3] = ((i = curr_pos + WIDTH - 1) > SIZE) ? 0 : map[i].nteam; \
  boxcases[4] = ((i = curr_pos - 1) < 0) ? 0 : map[i].nteam; \
  boxcases[5] = ((i = curr_pos - WIDTH - 1) < 0) ? 0 : map[i].nteam; \
  boxcases[6] = ((i = curr_pos - WIDTH) < 0) ? 0 : map[i].nteam; \
  boxcases[7] = ((i = curr_pos - WIDTH + 1) < 0) ? 0 : map[i].nteam;

struct  s_case
{
  int   nteam;
};

typedef struct	s_buffmsg
{
  int           mtype;
  char		mtext[1];
  int           pos;
}		t_buffmsg;

typedef struct	s_ipc
{
  key_t		key;
  int		shm_id;
  int		sem_id;
  int		msgq_id;
}		t_ipc;

typedef struct	s_affichage
{
  struct s_case *map;
  t_ipc *ipc;
}		t_affichage;

int		will_him_die(int *boxcase, int teamid);
int		is_him_alive(struct s_case *map, int curr_pos);
int		can_play_game(struct s_case *map);
void		core_display(struct s_case *map, t_ipc *ipc);
void		kill_all(t_ipc *ipc);
void		create_display(struct s_case *map, t_ipc *ipc);
int		lock(int sem_id);
void		unlock(int sem_id);
int		is_very_full(struct s_case *map);
int		create_player(struct s_case *map, t_ipc *ipc, int idteam);
struct s_case	*init_map(struct s_case *n_map);
void		init_first_player(t_ipc *ipc, int idteam);
void		init_other_players(t_ipc *ipc, int idteam);
void		init_ipc(char **av, t_ipc *ipc);
int		get_y(int pos);
int		get_x(int pos);
void		player_brain(struct s_case *map, int curr_pos, t_ipc *ipc);
int		search_ennemy(struct s_case *map, int curr_pos, t_ipc *ipc);
int		move_player_core(struct s_case *map, int curr_pos, t_ipc *ipc);
int		get_true_new_pos(int curr, int new_p);
void            push_msg(struct s_case *map, int new_index, t_ipc *ipc);
int		get_distance(int curr, int new_p);
int		get_random_pos(struct s_case *map, int curr);

#endif
