/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:51:34 by liabanzh          #+#    #+#             */
/*   Updated: 2017/05/01 13:51:35 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

void	delete_nbr(t_ptr **nbr)
{
	t_ptr	*tmp;

	while (*nbr != NULL)
	{
		tmp = (*nbr)->next;
		(*nbr)->ptr = NULL;
		free((*nbr));
		*nbr = tmp;
	}
}

void	delete_graph(t_lem **graph)
{
	t_lem	*tmp;

	tmp = *graph;
	while (*graph != NULL)
	{
		tmp = (*graph)->next;
		if ((*graph)->id != NULL)
			free((*graph)->id);
		(*graph)->id = NULL;
		delete_nbr(&((*graph)->nbr));
		if (*graph != NULL)
			free((*graph));
		*graph = tmp;
	}
}

void	delete_path(int **path)
{
	int		i;

	i = 0;
	while (path[i] != NULL)
	{
		free(path[i]);
		path[i] = NULL;
		i++;
	}
	free(path);
	path = NULL;
}

void	main_dop(t_lem **graph, t_comm **write, int **path)
{
	t_lem	*tmp;

	path = get_path(*graph);
	if (size_line(path[0]) < 2)
	{
		ft_putstr("\x1b[1;31mERROR\x1b[0m\n");
		return ;
	}
	if (*write != NULL)
		write_comments(write, 'w');
	tmp = *graph;
	while (tmp->flag != 's' && tmp != NULL)
		tmp = tmp->next;
	lets_go(path, *graph, tmp->aints);
	delete_graph(graph);
	delete_path(path);
}

int		main(void)
{
	t_lem	*graph;
	int		**path;
	t_comm	*write;

	path = NULL;
	write = NULL;
	if ((graph = parse(&write, 0, 0, NULL)) == NULL)
	{
		ft_putstr("\x1b[1;31mERROR\x1b[0m\n");
		delete_graph(&graph);
		write_comments(&write, 'd');
		return (0);
	}
	index_graph(graph);
	if (test(graph) == 1)
	{
		ft_putstr("\x1b[1;31mERROR\x1b[0m\n");
		delete_graph(&graph);
		write_comments(&write, 'd');
		return (0);
	}
	main_dop(&graph, &write, path);
	return (0);
}
