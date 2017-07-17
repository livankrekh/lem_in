/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:38:25 by liabanzh          #+#    #+#             */
/*   Updated: 2017/07/05 15:38:27 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

int		is_exist(char **arr, int i)
{
	int		j;

	j = 0;
	while (arr[j] != NULL)
		j++;
	if (i < j)
		return (1);
	return (0);
}

t_lem	*get_elem(t_lem *graph, char *id)
{
	while (graph != NULL)
	{
		if (!ft_strcmp(id, graph->id))
			break ;
		graph = graph->next;
	}
	return (graph);
}

int		parse_megadop(char **tmp, t_comm **write, int *status, t_lem *graph)
{
	if ((*tmp)[0] == '\0')
		return (-2);
	while (ft_strnstr(*tmp, "#", 1))
	{
		if (ft_strnstr(*tmp, "##", 2) && !ft_strnstr(*tmp, "###", 3))
		{
			graph->flag = (ft_strstr(*tmp, "start") ||
				ft_strstr((*tmp), "end")) ? (*tmp)[2] : '\0';
			ft_strdel(tmp);
			*status = gnl_mod(0, tmp, write);
			return (1);
		}
		else
			mem_debug(write, tmp);
		ft_strdel(tmp);
		*status = gnl_mod(0, tmp, write);
	}
	return (1);
}

int		bool_check(char *tmp)
{
	int		i;

	i = 0;
	if (tmp[0] == '\n' || ft_strchr(tmp, '-') ||
		ft_strchr(tmp, ' ') ||
		ft_atoi_long(tmp) > 2147483646 || ft_atoi(tmp) == 0)
		return (0);
	while (tmp[i] != '\0')
	{
		if (ft_isdigit(tmp[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

t_lem	*parse(t_comm **write, int res, int status, char *tmp)
{
	t_lem	*start;
	t_lem	*graph;

	if (gnl_mod(0, &tmp, write) < 1 || bool_check(tmp) == 0)
		return (NULL);
	res = ft_atoi(tmp);
	start = NULL;
	graph = start;
	free(tmp);
	status = gnl_mod(0, &tmp, write);
	while ((ft_strchr(tmp, ' ') || ft_strnstr(tmp, "#", 1)) && status)
	{
		mem_alloc(&graph, &start);
		if (ft_strnstr(tmp, "#", 1) || ft_strlen(tmp) == 0)
			if (parse_megadop(&tmp, write, &status, graph) == -2)
				return (start);
		if ((status = parse_dop_dohuia(&tmp, &start, res, write)) < 0)
			return (NULL);
	}
	if (!ft_strchr(tmp, '-') && !ft_strnstr(tmp, "#", 1))
		return (NULL);
	if (start != NULL && status == 1)
		parse_dop(&start, tmp, write);
	return (start);
}
