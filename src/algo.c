/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:23:34 by liabanzh          #+#    #+#             */
/*   Updated: 2017/05/22 13:23:35 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

int		*new_row(void)
{
	int		i;
	int		*res;

	i = 0;
	res = (int*)malloc(sizeof(int) * 10000);
	while (i < 10000)
		res[i++] = -1;
	return (res);
}

int		**new_path(void)
{
	int		**tmp;
	int		i;

	i = 0;
	tmp = (int**)malloc(sizeof(int*) * 10000);
	while (i < 10000)
		tmp[i++] = NULL;
	tmp[0] = (int*)malloc(sizeof(int) * 10000);
	i = 0;
	while (i < 10000)
		tmp[0][i++] = -1;
	return (tmp);
}

void	index_graph(t_lem *graph)
{
	int		i;

	i = 0;
	while (graph != NULL)
	{
		graph->ide = i;
		i++;
		graph = graph->next;
	}
}

void	find_path(t_lem *graph, int **path, int *p)
{
	t_lem	*tmp;
	t_ptr	*nbr;
	int		i;

	i = 0;
	tmp = graph;
	if (tmp->flag != 'e')
		tmp->visited = 1;
	nbr = tmp->nbr;
	while (path[*p][i] != -1)
		i++;
	path[*p][i] = graph->ide;
	if (tmp->flag == 'e')
	{
		(*p)++;
		path[*p] = new_row();
		return ;
	}
	while (nbr != NULL)
	{
		if (nbr->ptr->visited == 1)
			nbr = nbr->next;
		find_path(nbr->ptr, path, p);
		nbr = nbr->next;
	}
	path[*p][i] = -1;
	return ;
}

void	get_path(t_lem *graph)
{
	int		p;
	t_lem	*tmp;
	int		**road;
	int		i;

	tmp = graph;
	p = 0;
	i = 0;
	while (tmp != NULL && tmp->flag != 's')
		tmp = tmp->next;
	index_graph(graph);
	road = new_path();
	find_path(graph, road, &p);
	while (p >= 0)
	{
		while (road[p][i] != -1)
			printf("%d \n", road[p][i++]);
		printf("\n");
		p--;
	}
}
