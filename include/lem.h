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

typedef	struct s_lem t_lem;
typedef	struct s_group t_group;
typedef	struct s_road t_road;

typedef	struct 	s_ptr
{
	t_lem		*ptr;
	void		*next;
}				t_ptr;

struct 			s_lem
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

struct 	s_road
{
	int		*path;
	t_road	*next;
};

struct 	s_group
{
	t_road	*group;
	t_group	*next;
};

int				test(t_lem *graph);
int				**get_path(t_lem *graph);
void			print_farm(t_lem *graph);
void			lets_go(int **path, t_lem *graph, int aints);
void			print_path(int **road, int p, t_lem *graph);
int				get_min(int **path);

#endif
