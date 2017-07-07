/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:10:27 by liabanzh          #+#    #+#             */
/*   Updated: 2017/07/07 14:10:28 by liabanzh         ###   ########.fr       */
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

int		coord_test(char *tmp1, char *tmp2)
{
	int		i;

	i = 0;
	if (ft_atoi_long(tmp1) < 0 || ft_atoi_long(tmp2) < 0
		|| ft_atoi_long(tmp1) > 2147483647
		|| ft_atoi_long(tmp2) > 2147483647)
		return (0);
	while (tmp1[i] != '\0')
	{
		if (ft_isdigit(tmp1[i]) == 0)
			return (0);
		i++;
	}
	i = 0;
	while (tmp2[i] != '\0')
	{
		if (ft_isdigit(tmp2[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		redublication(t_lem *elem1, t_lem *elem2)
{
	t_ptr	*tmp;

	tmp = elem1->nbr;
	while (tmp != NULL)
	{
		if (tmp->ptr == elem2)
			return (1);
		tmp = tmp->next;
	}
	tmp = elem2->nbr;
	while (tmp != NULL)
	{
		if (tmp->ptr == elem1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
