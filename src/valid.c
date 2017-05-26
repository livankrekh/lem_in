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
	return (0);
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
