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
	tmp = (int**)malloc(sizeof(int*) * 100000);
	while (i < 100000)
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

void	print_path(int **road, int p, t_lem *graph)
{
	int		i;
	t_lem	*tmp;

	printf("\n");
	while (p >= 0)
	{
		i = 0;
		printf("#%d\n", p);
		while (road[p][i] != -1)
		{
			tmp = graph;
			while (tmp != NULL && tmp->ide != road[p][i])
				tmp = tmp->next;
			printf("%s ", tmp->id);
			i++;
		}
		printf("\n");
		p--;
	}
	printf("\n");
}

int		size_line(int *line)
{
	int		i;

	i = 0;
	while (line[i] != -1 && i < 10000)
		i++;
	return (i);
}

int		size_arr(int **arr)
{
	int		res;

	res = 0;
	while (arr[res] != NULL && res < 100000)
		res++;
	return (res);
}

void	find_path(t_lem *graph, int **path, int *p) // Need to correct
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
		while (nbr != NULL && nbr->ptr->visited == 1)
			nbr = nbr->next;
		if (nbr != NULL && nbr->ptr != NULL)
		{
			find_path(nbr->ptr, path, p);
			if (tmp->flag == 's')
			 	clear_visit(graph);
			if (size_line(path[*p]) > size_line(path[get_min(path)]) + 2 && graph->flag != 's')
			{
				path[*p][i] = -1;
				return ;
			}
			if (size_arr(path) > 97000)
				return ;
			if (nbr->ptr->flag == 'e')
				arr_dop(path, p, nbr->ptr->ide);
			else
				path[*p][i + 1] = -1;
			nbr = nbr->next;
		}
	}
	path[*p][i] = -1;
	graph->visited = 0;
	return ;
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
	find_path(tmp, road, &p);
	while (road[j] != NULL)
		j++;
	free(road[--j]);
	road[j] = NULL;
	print_path(road, --p, graph);
	return (road);
}
