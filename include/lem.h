/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:11:04 by liabanzh          #+#    #+#             */
/*   Updated: 2017/05/01 14:11:07 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef	struct s_lem	t_lem;
typedef	struct s_group	t_group;
typedef	struct s_road	t_road;
typedef	struct s_comm	t_comm;

typedef	struct	s_ptr
{
	t_lem		*ptr;
	void		*next;
}				t_ptr;

struct			s_lem
{
	char		*id;
	int			ide;
	int			x;
	int			y;
	int			aints;
	int			visited;
	char		flag;
	t_ptr		*nbr;
	t_lem		*next;
};

struct			s_road
{
	int			*path;
	t_road		*next;
};

struct			s_group
{
	t_road		*group;
	t_group		*next;
};

struct			s_comm
{
	char		*comment;
	t_comm		*next;
};

int				test(t_lem *graph);
int				**get_path(t_lem *graph);
void			print_farm(t_lem *graph);
void			lets_go(int **path, t_lem *graph, int aints);
void			print_path(int **road, int p, t_lem *graph);
int				get_min(int **path);
int				size_line(int *line);
void			go_path(t_road *solution, int aints, int count, t_lem *graph);
int				*copy_path(int *path);
int				minimal(t_road *first);
int				maximum(t_road *first);
void			delete_map(int **map);
int				*create_status(int aints);
char			*find_ide(int ide, t_lem *graph);
int				check(int status, int *road);
int				get_max(int **path);
t_road			*get_solution(t_group *list, int *shortest, int aints, int i);
void			include_group(int **path, int i, t_group **curr, int size);
t_lem			*parse(t_comm **write, int res, int status, char *tmp);
void			write_comments(t_comm **write, char flag);
int				parse_dop_dohuia(char **tmp, t_lem **graph, t_lem **s, int res);
void			mem_alloc(t_lem **graph, t_lem **start);
void			parse_dop(t_lem **graph, char *tmp);
t_lem			*get_elem(t_lem *graph, char *id);
void			delete_split(char **split);
int				is_exist(char **arr, int i);
int				**new_path(void);
int				*new_row(void);
int				size_arr(int **arr);
void			index_graph(t_lem *graph);

#endif
