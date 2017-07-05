/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 15:25:31 by liabanzh          #+#    #+#             */
/*   Updated: 2017/07/03 15:25:34 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

float	ranking(t_road *first, int aints)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (first != NULL)
	{
		count += size_line(first->path) - 1;
		i++;
		first = first->next;
	}
	return ((count + aints) / i);
}

t_road	*salut_minus(int *shortest)
{
	t_road	*res;

	res = (t_road*)malloc(sizeof(t_road));
	res->path = copy_path(shortest);
	res->next = NULL;
	return (res);
}

t_road	*get_solution(t_group *list, int *shortest, int aints, int i)
{
	int		salut;
	float	rank;
	float	rank_curr;
	t_group	*tmp;

	tmp = list;
	salut = -1;
	rank = size_line(shortest) + aints;
	while (tmp != NULL)
	{
		rank_curr = ranking(tmp->group, aints);
		if (rank_curr < rank)
		{
			rank = rank_curr;
			salut = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (salut == -1 || size_line(shortest) == 2)
		return (salut_minus(shortest));
	while (salut-- && list->next != NULL)
		list = list->next;
	return (list->group);
}
