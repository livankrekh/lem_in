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

int		subtest(char *id, t_lem *graph)
{
	int		res;

	res = 0;
	while (graph != NULL)
	{
		if (!ft_strcmp(id, graph->id))
			res++;
		graph = graph->next;
	}
	return (res);
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
		if (tmp->id[0] == '#')
			return (1);
		tmp = tmp->next;
	}
	return (test3(graph));
}

int		test(t_lem *graph)
{
	int		prov;
	t_lem	*ptr;

	prov = 0;
	ptr = graph;
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
