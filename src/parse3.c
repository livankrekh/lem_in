/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:47:47 by liabanzh          #+#    #+#             */
/*   Updated: 2017/07/05 15:47:48 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

void	delete_split(char **split)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
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

t_ptr	*parse_dop2(t_lem **elem)
{
	t_ptr	*ptr;

	ptr = (*elem)->nbr;
	if (ptr == NULL)
	{
		(*elem)->nbr = (t_ptr*)malloc(sizeof(t_ptr));
		ptr = (*elem)->nbr;
	}
	else if ((*elem) != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = (t_ptr*)malloc(sizeof(t_ptr));
		ptr = ptr->next;
	}
	return (ptr);
}

void	include_ptr(t_lem **elem1, t_lem **elem2)
{
	t_ptr	*ptr;

	ptr = parse_dop2(elem1);
	ptr->ptr = *elem2;
	ptr->next = NULL;
	ptr = parse_dop2(elem2);
	ptr->ptr = *elem1;
	ptr->next = NULL;
}

void	parse_dop(t_lem **graph, char *tmp)
{
	t_lem	*elem1;
	t_lem	*elem2;
	char	**tmp2;

	while (tmp && *graph && tmp[0] != '\0')
	{
		while (tmp[0] == '#' && tmp[1] != '#')
		{
			free(tmp);
			get_next_line(0, &tmp);
		}
		tmp2 = ft_strsplit(tmp, '-');
		elem1 = get_elem(*graph, tmp2[0]);
		elem2 = get_elem(*graph, tmp2[1]);
		if (elem1 != NULL && elem2 != NULL && redublication(elem1, elem2) == 0)
			include_ptr(&elem1, &elem2);
		free(tmp);
		tmp = NULL;
		delete_split(tmp2);
		get_next_line(0, &tmp);
	}
}
