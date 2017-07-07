/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:01:18 by liabanzh          #+#    #+#             */
/*   Updated: 2017/05/19 17:01:19 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

int		test_coord(t_lem *tmp, t_lem *graph)
{
	while (graph != NULL)
	{
		if (graph->ide != tmp->ide)
			if (graph->x == tmp->x && graph->y == tmp->y)
				return (1);
		graph = graph->next;
	}
	return (0);
}

int		test3(t_lem *graph)
{
	t_lem	*tmp;

	tmp = graph;
	while (tmp != NULL)
	{
		if (subtest(tmp->id, graph) > 1)
			return (1);
		tmp = tmp->next;
	}
	tmp = graph;
	while (tmp != NULL)
	{
		if (ft_strchr(tmp->id, '-'))
			return (1);
		if (tmp->flag == 'e' && tmp->nbr == NULL)
			return (1);
		if (test_coord(tmp, graph) == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		test2(t_lem *graph)
{
	t_lem	*tmp;
	t_ptr	*nbr;

	tmp = graph;
	while (tmp != NULL)
	{
		nbr = tmp->nbr;
		while (nbr != NULL)
		{
			if (nbr->ptr->id == tmp->id)
				return (1);
			nbr = nbr->next;
		}
		if (tmp->flag == 's')
			if (tmp->aints < 1)
				return (1);
		if (tmp->id == NULL)
			break ;
		if (tmp->id[0] == '#')
			return (1);
		tmp = tmp->next;
	}
	return (test3(graph));
}

void	test_graph(t_lem **graph)
{
	t_lem *tmp;
	t_lem *tmp2;

	tmp = *graph;
	tmp2 = NULL;
	while (tmp != NULL)
	{
		if (tmp->id == NULL)
		{
			if (tmp2 == NULL)
			{
				free(*graph);
				*graph = NULL;
			}
			else
			{
				tmp2->next = tmp->next;
				free(tmp);
				tmp = tmp2;
			}
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
}

int		test(t_lem *graph)
{
	int		prov;
	t_lem	*ptr;

	prov = 0;
	ptr = graph;
	test_graph(&graph);
	while (ptr != NULL)
	{
		if (ptr->flag == 's')
			prov++;
		ptr = ptr->next;
	}
	if (prov != 1)
		return (1);
	ptr = graph;
	prov = 0;
	while (ptr != NULL)
	{
		if (ptr->flag == 'e')
			prov++;
		ptr = ptr->next;
	}
	if (prov != 1)
		return (1);
	return (test2(graph));
}
