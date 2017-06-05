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

void	include_group(int **path, int i, t_group **curr)
{
	t_group	*tmp;
	t_group	*ptr2;
	t_road	*tmp2;
	t_road	*ptr;
	int		curr_i;

	curr_i = 0;
	tmp = (t_group*)malloc(sizeof(t_group));
	tmp->group = (t_road*)malloc(sizeof(t_road));
	tmp->next = NULL;
	tmp->group->path = copy_path(path[i]);
	tmp->group->next = NULL;
	ptr = tmp->group;
	while (path[curr_i] != NULL)
	{
		if (compare(path[curr_i], tmp->group) == 0)
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

t_group	*get_groups(int **path)
{
	t_group	*start;
	int		i;

	i = 0;
	start = NULL;
	while (path[i] != NULL)
		include_group(path, i++, &start);
	return (start);
}

void	lets_go(int **path, t_lem *graph, int aints)
{
	int		rathio;
	t_group	*list;
	int		i;
	int		j;

	i = 0;
	rathio = get_min(path);
	graph = NULL;
	list = get_groups(path);
	while (list != NULL)
	{
		printf("GROUP #%d\n", i);
		while (list->group != NULL)
		{
			j = 0;
			while (list->group->path[j] != -1)
				printf("%d ", list->group->path[j++]);
			printf("\n");
			list->group = list->group->next;
		}
		printf("\n");
		list = list->next;
		i++;
	}
	aints = 0;
}

// int		**go_path(int **path, int rathio)
// {
// 	int		**new;
// 	int		i;
// 	int		min;
// 	int		count;
// 	int		j;

// 	i = 0;
// 	min = 0;
// 	count = 0;
// 	j = 0;
// 	new = (int**)malloc(sizeof(int*) * 1000);
// 	while (path[rathio][min] != -1)
// 		min++;
// 	while (i < 1000)
// 		new[i++] = NULL;
// 	copy_path(new, path[rathio]);
// 	i = 0;
// 	while (path[i] != NULL)
// 	{
// 		if (compare(path[i], path[rathio]) == 0)
// 			copy_path(new, path[i]);
// 		i++;
// 	}
// 	return (new);
// }
