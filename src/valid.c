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
	t_lem	*ptr;

	ptr = graph;
	while (ptr != NULL)
	{
		if (ptr->flag == 's')
			if (ptr->aints < 0)
				return (1);
		if (ptr->id[0] == '#')
			return (1);
		ptr = ptr->next;
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
