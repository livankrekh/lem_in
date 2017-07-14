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

t_comm	*include_comment(char *tmp)
{
	t_comm	*res;

	res = (t_comm*)malloc(sizeof(t_comm));
	res->comment = ft_strnew(ft_strlen(tmp) - 1);
	ft_strcpy(res->comment, &tmp[1]);
	res->flag = 'c';
	res->next = NULL;
	return (res);
}

// int		parse_megadop(char **tmp, t_comm **write, t_lem **graph, t_lem **start)
// {
// 	t_comm	*comm;
// 	int		status;

// 	status = (*tmp == NULL || (*tmp)[0] == '\0') ? 0 : 1;
// 	while (status && (*tmp)[0] == '#')
// 	{
// 		if (ft_strnstr("##start", *tmp, 7) || ft_strnstr("##end", *tmp, 5))
// 		{
// 			mem_alloc(graph, start);
// 			(*graph)->flag = (ft_strstr(*tmp, "start") ||
// 						ft_strstr((*tmp), "end")) ? (*tmp)[2] : '\0';
// 			ft_strdel(tmp);
// 			return (gnl_mod(0, tmp, write));
// 		}
// 		else if ((ft_strnstr("#", *tmp, 1) && !ft_strnstr("##", *tmp, 2)) ||
// 			ft_strnstr("###", *tmp, 3))
// 		{
// 			if (*write == NULL)
// 				*write = include_comment(*tmp);
// 			else
// 			{
// 				comm = *write;
// 				while (comm->next != NULL)
// 					comm = comm->next;
// 				comm->next = include_comment(*tmp);
// 			}
// 			ft_strdel(tmp);
// 			status = gnl_mod(0, tmp, write);
// 		}
// 	}
// 	return (status);
// }

int		parse_megadop(char **tmp, t_comm **write, int *status, t_lem *graph)
{
	t_comm	*comm;

	if ((*tmp)[0] == '\0')
		return (-2);
	if ((*tmp)[0] == '#' && (*tmp)[1] == '#')
	{
		graph->flag = (ft_strstr(*tmp, "start") ||
			ft_strstr((*tmp), "end")) ? (*tmp)[2] : '\0';
	}
	else if ((*tmp)[0] == '#' && (*tmp)[1] != '#')
	{
		if (*write == NULL)
			*write = include_comment(*tmp);
		else
		{
			comm = *write;
			while (comm->next != NULL)
				comm = comm->next;
			comm->next = include_comment(*tmp);
		}
	}
	ft_strdel(tmp);
	*status = gnl_mod(0, tmp, write);
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
	while ((ft_strchr(tmp, ' ') || tmp[0] == '#') && status)
	{
		mem_alloc(&graph, &start);
		while (tmp[0] == '#' || tmp[0] == '\0')
			if (parse_megadop(&tmp, write, &status, graph) == -2)
				return (start);
		if ((status = parse_dop_dohuia(&tmp, &start, res, write)) < 0)
			return (NULL);
	}
	if (!ft_strchr(tmp, '-') && tmp[0] != '#')
		return (NULL);
	if (start != NULL && status == 1)
		parse_dop(&start, tmp, write);
	return (start);
}
