/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_dop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:48:40 by liabanzh          #+#    #+#             */
/*   Updated: 2017/06/23 17:48:41 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

int		check(int status, int *road)
{
	int		i;

	i = 1;
	while (road[i] != -1)
	{
		if (status == road[i])
			return (road[i + 1]);
		i++;
	}
	return (-1);
}

char	*find_ide(int ide, t_lem *graph)
{
	while (graph != NULL)
	{
		if (graph->ide == ide)
			return (graph->id);
		graph = graph->next;
	}
	return (NULL);
}

int		*create_status(int aints)
{
	int		*status;
	int		index;

	index = 0;
	status = (int*)malloc(sizeof(int) * (aints + 1));
	while (index < aints)
		status[index++] = -1;
	status[index] = -3;
	return (status);
}

void	delete_map(int **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}
