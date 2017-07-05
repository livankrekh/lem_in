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

void	write_comments(t_comm **write, char flag)
{
	t_comm	*tmp;

	if (flag == 'w')
		ft_putstr("\x1b[1;31mComments:\x1b[0m\n");
	while (*write != NULL)
	{
		tmp = (*write)->next;
		if (flag == 'w')
		{
			ft_putstr("\x1b[1;4;32m");
			ft_putstr((*write)->comment);
			ft_putstr("\x1b[0m");
			ft_putstr("\n");
		}
		free((*write)->comment);
		(*write)->comment = NULL;
		free(*write);
		*write = tmp;
	}
	*write = NULL;
}

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
