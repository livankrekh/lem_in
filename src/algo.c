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

void	arr_dop(int **path, int *p, int id)
{
	int		i;

	i = 0;
	while (i < 10000)
		path[*p][i++] = -1;
	i = 0;
	while (path[*p - 1][i] != -1 && path[*p - 1][i] != id)
	{
		path[*p][i] = path[*p - 1][i];
		i++;
	}
}

void	clear_visit(t_lem *graph)
{
	while (graph != NULL)
	{
		if (graph->flag != 's')
			graph->visited = 0;
		graph = graph->next;
	}
}

int		algo_dop(t_ptr **nbr, t_lem *tmp, int **path, int i)
{
	int		p;

	p = 0;
	while (path[p] != NULL)
		p++;
	p--;
	if (tmp->flag == 's')
		clear_visit(tmp);
	if (size_line(path[p]) > size_line(path[get_min(path)]) + 2
		&& tmp->flag != 's')
	{
		path[p][i] = -1;
		return (-1);
	}
	if (size_arr(path) > 97000)
		return (-1);
	if ((*nbr)->ptr->flag == 'e')
		arr_dop(path, &p, (*nbr)->ptr->ide);
	else
		path[p][i + 1] = -1;
	*nbr = (*nbr)->next;
	return (0);
}

int		*find_path(t_lem *graph, int **path, int *p, int i)
{
	t_lem	*tmp;
	t_ptr	*nbr;

	tmp = graph;
	(tmp->flag != 'e') ? tmp->visited = 1 : 0;
	nbr = tmp->nbr;
	while (path[*p][i] != -1)
		i++;
	path[*p][i] = graph->ide;
	if (tmp->flag == 'e')
		return ((path[++(*p)] = new_row()));
	while (nbr != NULL)
	{
		while (nbr != NULL && nbr->ptr->visited == 1)
			nbr = nbr->next;
		if (nbr != NULL && nbr->ptr != NULL)
		{
			find_path(nbr->ptr, path, p, 0);
			if (algo_dop(&nbr, tmp, path, i) == -1)
				return (NULL);
		}
	}
	path[*p][i] = -1;
	graph->visited = 0;
	return (NULL);
}

int		**get_path(t_lem *graph)
{
	int		p;
	t_lem	*tmp;
	int		**road;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = graph;
	p = 0;
	while (tmp != NULL && tmp->flag != 's')
		tmp = tmp->next;
	index_graph(graph);
	road = new_path();
	find_path(tmp, road, &p, 0);
	while (road[j] != NULL)
		j++;
	free(road[--j]);
	road[j] = NULL;
	return (road);
}
