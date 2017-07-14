/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 15:30:25 by liabanzh          #+#    #+#             */
/*   Updated: 2017/07/03 15:30:26 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

int		compare2(int *comp, int *origin)
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

int		compare(int *comp, t_road *start)
{
	while (start != NULL)
	{
		if (compare2(comp, start->path) == 1)
			return (1);
		start = start->next;
	}
	return (0);
}

t_group	*create_tmp(int **path, int i)
{
	t_group	*tmp;

	tmp = (t_group*)malloc(sizeof(t_group));
	tmp->group = (t_road*)malloc(sizeof(t_road));
	tmp->next = NULL;
	tmp->group->path = copy_path(path[i]);
	tmp->group->next = NULL;
	return (tmp);
}

void	search_path(int **path, int size, t_group *tmp)
{
	t_road	*ptr;
	int		curr_i;
	t_road	*tmp2;

	curr_i = 0;
	ptr = tmp->group;
	while (path[curr_i] != NULL)
	{
		if (size == size_line(path[curr_i]) &&
		compare(path[curr_i], tmp->group) == 0)
		{
			tmp2 = (t_road*)malloc(sizeof(t_road));
			tmp2->path = copy_path(path[curr_i]);
			tmp2->next = NULL;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = tmp2;
		}
		curr_i++;
	}
}

void	include_group(int **path, int i, t_group **curr, int size)
{
	t_group	*tmp;
	t_group	*ptr2;

	tmp = create_tmp(path, i);
	while (size <= size_line(path[get_max(path)]))
	{
		search_path(path, size, tmp);
		size++;
	}
	ptr2 = *curr;
	if (*curr == NULL)
		*curr = tmp;
	else
	{
		while (ptr2->next != NULL)
			ptr2 = ptr2->next;
		ptr2->next = tmp;
	}
}
