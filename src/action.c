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
	while (path[curr] != NULL && curr < 100000)
	{
		i = 0;
		while (path[curr][i] != -1 && i < 10000)
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

int		get_max(int **path)
{
	int		res;
	int		curr;
	int		max;

	res = 0;
	curr = 0;
	max = 0;
	while (path[curr] != NULL && curr < 100000)
	{
		if (max < size_line(path[curr]))
		{
			max = size_line(path[curr]);
			res = curr;
		}
		curr++;
	}
	return (res);
}

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

int		*copy_path(int *path)
{
	int		*new;
	int		j;

	j = 0;
	if (path == NULL)
		return (NULL);
	while (path[j] != -1)
		j++;
	new = (int*)malloc(sizeof(int) * (j + 1));
	j = 0;
	while (path[j] != -1)
	{
		new[j] = path[j];
		j++;
	}
	new[j] = -1;
	return (new);
}

void	include_group(int **path, int i, t_group **curr, int size)
{
	t_group	*tmp;
	t_group	*ptr2;
	t_road	*tmp2;
	t_road	*ptr;
	int		curr_i;

	tmp = (t_group*)malloc(sizeof(t_group));
	tmp->group = (t_road*)malloc(sizeof(t_road));
	tmp->next = NULL;
	tmp->group->path = copy_path(path[i]);
	tmp->group->next = NULL;
	ptr = tmp->group;
	while (size <= size_line(path[get_max(path)]))
	{
		curr_i = 0;
		while (path[curr_i] != NULL)
		{
			if (size == size_line(path[curr_i]) && compare(path[curr_i], tmp->group) == 0)
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

int		minimal(t_road *first)
{
	int		res;

	if (first != NULL)
	{
		res = size_line(first->path);
		first = first->next;
	}
	else
		return (0);
	while (first != NULL)
	{
		if (res > size_line(first->path))
			res = size_line(first->path);
		first = first->next;
	}
	return (res);
}

int		maximum(t_road *first)
{
	int		res;

	res = 0;
	while (first != NULL)
	{
		if (res < size_line(first->path))
			res = size_line(first->path);
		first = first->next;
	}
	return (res);
}

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

float	ranking(t_road *first, int aints)
{
	int		i;
	int		count;
	// int		min;
	// int		max;
	// t_road	*tmp;

	// i = count_path(first);
	count = 0;
	i = 0;
	// min = minimal(first);
	// max = maximum(first);
	// if (aints > i)
	// 	return ((max + aints) / i);
	// i = 0;
	// while (min <= max && i < aints)
	// {
	// 	tmp = first;
	// 	while (first != NULL && i < aints)
	// 	{
	// 		if (size_line(first->path) == min)
	// 			i++;
	// 		first = first->next;
	// 	}
	// 	count = min;
	// 	min++;
	// }
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

t_road	*get_solution(t_group *list, int *shortest, int aints)
{
	int		salut;
	float	rank;
	float	rank_curr;
	int		i;
	int		dop;
	t_group	*tmp;

	tmp = list;
	salut = -1;
	i = 0;
	dop = 0;
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
	solution = get_solution(list, path[rathio], aints);
	go_path(solution, aints, count_path(solution), graph);
	delete_solution(&list);
}
