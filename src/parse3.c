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

void	parse_comment(t_comm **write, char **tmp)
{
	t_comm	*comm;

	if (*write == NULL)
		*write = include_comment(*tmp);
	else
	{
		comm = *write;
		while (comm->next != NULL)
			comm = comm->next;
		comm->next = include_comment(*tmp);
	}
	free(*tmp);
	get_next_line(0, tmp);
}

void	parse_dop(t_lem **graph, char *tmp, t_comm **write)
{
	t_lem	*elem1;
	t_lem	*elem2;
	char	**tmp2;

	while (tmp && *graph && tmp[0] != '\0' &&
		(ft_strchr(tmp, '-') || tmp[0] == '#'))
	{
		while (tmp[0] == '#')
			parse_comment(write, &tmp);
		if (ft_strchr(tmp, '-')[1] == '\0')
			return ;
		tmp2 = ft_strsplit(tmp, '-');
		elem1 = get_elem(*graph, tmp2[0]);
		elem2 = get_elem(*graph, tmp2[1]);
		if (elem1 == NULL || elem2 == NULL)
			return ;
		if (redublication(elem1, elem2) == 0)
			include_ptr(&elem1, &elem2);
		free(tmp);
		tmp = NULL;
		delete_split(tmp2);
		get_next_line(0, &tmp);
	}
}
