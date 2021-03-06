/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:44:47 by liabanzh          #+#    #+#             */
/*   Updated: 2017/07/05 15:44:49 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

t_lem	*create_graph(void)
{
	t_lem	*res;

	res = (t_lem*)malloc(sizeof(t_lem));
	res->id = NULL;
	res->x = -1;
	res->y = -1;
	res->nbr = NULL;
	res->visited = 0;
	res->flag = '0';
	res->aints = 0;
	res->next = NULL;
	return (res);
}

void	mem_alloc(t_lem **graph, t_lem **start)
{
	if (*graph == NULL)
	{
		*start = create_graph();
		*graph = *start;
	}
	else
	{
		(*graph)->next = create_graph();
		(*graph) = (*graph)->next;
	}
}

int		elem_write(char **tmp, t_lem *graph, int res, t_comm **write)
{
	int		status;
	char	**tmp2;

	tmp2 = ft_strsplit(*tmp, ' ');
	if (is_exist(tmp2, 0) == 0 || is_exist(tmp2, 1) == 0
		|| is_exist(tmp2, 2) == 0)
		return (-2);
	graph->id = ft_strnew(ft_strlen(tmp2[0]));
	ft_strcpy(graph->id, tmp2[0]);
	if (coord_test(tmp2[1], tmp2[2]) == 0)
		return (-2);
	graph->x = (is_exist(tmp2, 1) == 1) ? ft_atoi(tmp2[1]) : -1;
	graph->y = (is_exist(tmp2, 2) == 1) ? ft_atoi(tmp2[2]) : -1;
	graph->nbr = NULL;
	graph->visited = 0;
	graph->flag = (graph->flag != 's' && graph->flag != 'e')
		? '\0' : graph->flag;
	graph->aints = (graph->flag == 's') ? res : 0;
	free(*tmp);
	status = gnl_mod(0, tmp, write);
	delete_split(tmp2);
	return (status);
}

void	parse_else(t_lem **graph, t_lem **start)
{
	t_lem	*tmp;

	(*graph)->next = NULL;
	*graph = *start;
	tmp = NULL;
	while (*graph != NULL)
	{
		if ((*graph)->id == NULL)
		{
			free(*graph);
			*graph = NULL;
			if (tmp != NULL)
				tmp->next = NULL;
		}
		tmp = *graph;
		*graph = (*graph)->next;
	}
	*graph = *start;
	if (*graph != NULL && (*graph)->next != NULL)
	{
		while ((*graph)->next->next != NULL)
			*graph = (*graph)->next;
		free((*graph)->next);
		(*graph)->next = NULL;
	}
}

int		parse_dop_dohuia(char **tmp, t_lem **s, int res, t_comm **write)
{
	int		status;
	t_lem	*graph;

	status = 1;
	graph = *s;
	if (graph != NULL)
		while (graph->next != NULL)
			graph = graph->next;
	if (ft_strlen(*tmp) != 0 && ft_strchr(*tmp, ' ') &&
		!ft_strnstr(*tmp, "#", 1))
	{
		if (ft_strnstr(*tmp, "L", 1) || ft_strchr(*tmp, '-'))
			return (-2);
		return (elem_write(tmp, graph, res, write));
	}
	else if (ft_strnstr(*tmp, "#", 1))
		return (-2);
	else if (!ft_strchr(*tmp, '-'))
	{
		if (ft_strchr(*tmp, ' '))
			return (-2);
		parse_else(&graph, s);
	}
	return (status);
}
