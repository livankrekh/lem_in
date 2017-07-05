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

void	map_dop(int **res, t_road *solution, int aints)
{
	int		min;
	int		max;
	t_road	*tmp;
	int		i;

	i = 0;
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

int		**get_map(t_road *solution, int aints, int count_path)
{
	int		**res;
	int		i;

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
		map_dop(res, solution, aints);
	return (res);
}

void	print_l(int index, int *status, int check, t_lem *graph)
{
	int		finish;

	ft_putstr("\x1b[1;33mL\x1b[0m");
	ft_putstr("\x1b[32m");
	ft_putnbr(index + 1);
	ft_putchar('-');
	ft_putstr(find_ide(check, graph));
	ft_putstr("\x1b[0m");
	ft_putchar(' ');
	while (graph != NULL)
	{
		if (graph->flag == 'e')
			break ;
		graph = graph->next;
	}
	finish = graph->ide;
	if (check == finish)
		status[index] = -2;
	else
		status[index] = check;
}

void	go_go_go(int **map, int aints, t_lem *graph)
{
	int		*status;
	int		index;
	int		j;

	status = create_status(aints);
	while (status[aints - 1] != -2)
	{
		j = 0;
		while (map[j] != NULL)
		{
			index = 0;
			while (status[index] != -1 && status[index] != -3)
			{
				if (check(status[index], map[j]) >= 0)
					print_l(index, status, check(status[index], map[j]), graph);
				index++;
			}
			if (status[index] == -1)
				print_l(index, status, map[j][1], graph);
			j++;
		}
		ft_putchar('\n');
	}
	free(status);
	status = NULL;
}

void	go_path(t_road *solution, int aints, int count, t_lem *graph)
{
	int		**map;
	int		i;

	i = 0;
	map = get_map(solution, aints, count);
	go_go_go(map, aints, graph);
	delete_map(map);
}
