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

int		parse_comment(t_comm **write, char **tmp)
{
	t_comm	*comm;

	if (tmp == NULL || tmp[0] == '\0')
		return (0);
	if (*write == NULL)
		*write = include_comment(*tmp);
	else
	{
		comm = *write;
		while (comm->next != NULL)
			comm = comm->next;
		comm->next = include_comment(*tmp);
	}
	ft_strdel(tmp);
	return (gnl_mod(0, tmp, write));
}

void	parse_dop(t_lem **graph, char *tmp, t_comm **write)
{
	t_lem	*elem1;
	t_lem	*elem2;
	char	**tmp2;
	int		status;

	status = 1;
	while (tmp && *graph && status && ft_strlen(tmp) != 0 &&
		(ft_strchr(tmp, '-') || ft_strnstr(tmp, "#", 1)))
	{
		while (tmp[0] == '#')
			if ((status = parse_comment(write, &tmp)) <= 0)
				return ;
		if (ft_strlen(&(ft_strchr(tmp, '-')[1])) == 0 || tmp[0] == '\0')
			return ;
		tmp2 = ft_strsplit(tmp, '-');
		elem1 = get_elem(*graph, tmp2[0]);
		elem2 = get_elem(*graph, tmp2[1]);
		if (elem1 == NULL || elem2 == NULL)
			return ;
		if (redublication(elem1, elem2) == 0)
			include_ptr(&elem1, &elem2);
		ft_strdel(&tmp);
		delete_split(tmp2);
		status = gnl_mod(0, &tmp, write);
	}
}
