/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 18:54:21 by liabanzh          #+#    #+#             */
/*   Updated: 2017/06/10 18:54:23 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

int		**get_map(t_road *solution, int aints, int count_path)
{
	int		**res;
	int		i;
	int		min;
	int		max;
	t_road	*tmp;

	i = 0;
	res = (int**)malloc(sizeof(int*) * (count_path + 1));
	while (i < count_path + 1)
		res[i++] = NULL;
	i = 0;
	if (aints >= count_path)
		while (i < count_path && solution != NULL)
		{
			res[i] = copy_path(solution->path);
			solution = solution->next;
			i++;
		}
	else
	{
		min = minimal(solution);
		max = maximum(solution);
		while (min <= max && i < aints)
		{
			tmp = solution;
			while (tmp != NULL && i < aints)
			{
				if (size_line(tmp->path) == min)
				{
					res[i] = copy_path(tmp->path);
					i++;
				}
				tmp = tmp->next;
			}
			min++;
		}
	}
	return (res);
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

void	go_go_go(int **map, int aints, t_lem *graph, int finish)
{
	int		*status;
	int		index;
	int		j;

	index = 0;
	status = (int*)malloc(sizeof(int) * (aints + 1));
	while (index < aints)
		status[index++] = -1;
	status[index] = -3;
	while (status[aints - 1] != -2)
	{
		j = 0;
		while (map[j] != NULL)
		{
			index = 0;
			while (status[index] != -1 && status[index] != -3)
			{
				if (check(status[index], map[j]) >= 0)
				{
					ft_putchar('L');
					ft_putnbr(index + 1);
					ft_putchar('-');
					ft_putstr(find_ide(check(status[index], map[j]), graph));
					ft_putchar(' ');
					if (check(status[index], map[j]) == finish)
						status[index] = -2;
					else
						status[index] = check(status[index], map[j]);
				}
				index++;
			}
			if (status[index] == -1)
			{
				ft_putchar('L');
				ft_putnbr(index + 1);
				ft_putchar('-');
				ft_putstr(find_ide(map[j][1], graph));
				ft_putchar(' ');
				if (map[j][1] == finish)
					status[index] = -2;
				else
					status[index] = map[j][1];
			}
			j++;
		}
		ft_putchar('\n');
	}
	free(status);
	status = NULL;
}

void	go_path(t_road *solution, int aints, int count_path, t_lem *graph)
{
	int		**map;
	int		finish;
	int		i;
	
	i = 0;
	map = get_map(solution, aints, count_path);
	finish = map[0][size_line(map[0]) - 1];
	go_go_go(map, aints, graph, finish);
	delete_map(map);
}
