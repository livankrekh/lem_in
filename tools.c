/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 15:20:26 by liabanzh          #+#    #+#             */
/*   Updated: 2017/07/03 15:20:27 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

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
