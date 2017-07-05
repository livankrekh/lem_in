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

int		count_path(t_road *first)
{
	int		i;

	i = 0;
	while (first != NULL)
	{
		first = first->next;
		i++;
	}
	return (i);
}

t_group	*get_groups(int **path, int min_size)
{
	t_group	*start;
	int		i;

	i = 0;
	start = NULL;
	while (path[i] != NULL)
		include_group(path, i++, &start, min_size);
	return (start);
}

void	delete_road(t_road **curr)
{
	t_road	*tmp;

	while (*curr != NULL)
	{
		tmp = (*curr)->next;
		free((*curr)->path);
		(*curr)->path = NULL;
		(*curr)->next = NULL;
		free(*curr);
		*curr = tmp;
	}
}

void	delete_solution(t_group **list)
{
	t_group	*tmp;

	while (*list != NULL)
	{
		tmp = (*list)->next;
		delete_road(&((*list)->group));
		(*list)->next = NULL;
		free(*list);
		*list = tmp;
	}
}

void	lets_go(int **path, t_lem *graph, int aints)
{
	int		rathio;
	t_group	*list;
	int		i;
	t_road	*solution;

	i = 0;
	rathio = get_min(path);
	list = get_groups(path, size_line(path[rathio]));
	solution = get_solution(list, path[rathio], aints, 0);
	go_path(solution, aints, count_path(solution), graph);
	delete_solution(&list);
}
