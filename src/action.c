/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:09:59 by liabanzh          #+#    #+#             */
/*   Updated: 2017/05/27 16:10:01 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

int		get_min(int **path)
{
	int		res;
	int		i;
	int		min;
	int		curr;

	res = 0;
	min = 100000;
	curr = 0;
	while (path[curr] != NULL)
	{
		i = 0;
		while (path[curr][i] != -1)
			i++;
		if (i < min && i != 0)
		{
			min = i;
			res = curr;
		}
		curr++;
	}
	return (res);
}

void	copy_path(int **new, int *path)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (new[i] != NULL)
		i++;
	while (path[j] != -1)
		j++;
	new[i] = (int*)malloc(sizeof(int) * (j + 1));
	i = 0;
	j = 0;
	while (path[j] != -1)
	{
		new[i][j] = path[j];
		j++;
	}
	new[i][j] = -1;
}

int		compare(int *comp, int *origin) // Need to correct
{
	int		i;
	int		j;

	j = 0;
	while (comp[j] != -1)
		j++;
	j -= 2;
	while (j > 0)
	{
		i = 0;
		while (origin[i] != -1)
			if (origin[i++] == comp[j])
				return (1);
		j--;
	}
	return (0);
}

int		**go_path(int **path, int rathio)
{
	int		**new;
	int		i;
	int		min;
	int		count;

	i = 0;
	min = 0;
	count = 0;
	new = (int**)malloc(sizeof(int*) * 1000);
	while (path[rathio][min] != -1)
		min++;
	while (i < 1000)
		new[i++] = NULL;
	copy_path(new, path[rathio]);
	i = 0;
	while (path[i] != NULL)
	{
		if (compare(path[i], path[rathio]) == 0)
			copy_path(new, path[i]);
		i++;
	}
	return (new);
}

void	lets_go(int **path, t_lem *graph)
{
	int		rathio;
	int		**new_roads;
	int		p;

	p = 0;
	rathio = get_min(path);
	new_roads = go_path(path, rathio);
	while (new_roads[p] != NULL)
		p++;
	p--;
	print_path(new_roads, p, graph);
}
