/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:46:28 by liabanzh          #+#    #+#             */
/*   Updated: 2017/07/05 16:46:30 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

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

int		size_line(int *line)
{
	int		i;

	i = 0;
	if (line == NULL)
		return (0);
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
