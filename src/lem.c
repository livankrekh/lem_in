/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:51:34 by liabanzh          #+#    #+#             */
/*   Updated: 2017/05/01 13:51:35 by liabanzh         ###   ########.fr       */
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
			break;
		graph = graph->next;
	}
	return (graph);
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

void	parse_dop(t_lem **graph, char *tmp)
{
	t_lem	*elem1;
	t_lem	*elem2;
	t_ptr	*ptr;
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
		{
			ptr = elem1->nbr;
			if (ptr == NULL)
			{
				elem1->nbr = (t_ptr*)malloc(sizeof(t_ptr));
				ptr = elem1->nbr;
			}
			else if (elem2 != NULL)
			{
				while (ptr->next != NULL)
					ptr = ptr->next;
				ptr->next = (t_ptr*)malloc(sizeof(t_ptr));
				ptr = ptr->next;
			}
			ptr->ptr = elem2;
			ptr->next = NULL;
			ptr = elem2->nbr;
			if (ptr == NULL)
			{
				elem2->nbr = (t_ptr*)malloc(sizeof(t_ptr));
				ptr = elem2->nbr;
			}
			else if (elem2 != NULL)
			{
				while (ptr->next != NULL)
					ptr = ptr->next;
				ptr->next = (t_ptr*)malloc(sizeof(t_ptr));
				ptr = ptr->next;
			}
			ptr->ptr = elem1;
			ptr->next = NULL;
		}
		free(tmp);
		tmp = NULL;
		delete_split(tmp2);
		get_next_line(0, &tmp);
	}
}

t_comm	*include_comment(char *tmp)
{
	t_comm	*res;

	res = (t_comm*)malloc(sizeof(t_comm));
	res->comment = ft_strnew(ft_strlen(tmp) - 1);
	ft_strcpy(res->comment, &tmp[1]);
	res->next = NULL;
	return (res);
}

t_lem	*create_graph()
{
	t_lem	*res;

	res = (t_lem*)malloc(sizeof(t_lem));
	res->id = NULL;
	res->x = -1;
	res->y = -1;
	res->nbr = NULL;
	res->visited = 0;
	res->flag = '0';
	res->aints = 0;
	res->next = NULL;
	return (res);
}

t_lem	*parse(t_comm **write)
{
	int		res;
	char	**tmp2;
	char	*tmp;
	t_lem	*start;
	t_lem	*graph;
	t_comm	*comm;
	int 	status;

	if (get_next_line(0, &tmp) < 1 || tmp[0] == '\n' || ft_strchr(tmp, '-') || ft_strchr(tmp, ' '))
		return (NULL);
	res = ft_atoi(tmp);
	start = NULL;
	graph = start;
	free(tmp);
	status = get_next_line(0, &tmp);
	while (ft_strchr(tmp, ' ') || (tmp[0] == '#'))
	{
		if (graph == NULL)
		{
			start = create_graph();
			graph = start;
		}
		else
		{
			graph->next = create_graph();
			graph = graph->next;
		}
		while (tmp[0] == '#' || tmp[0] == '\0')
		{
			if (tmp[0] == '#' && tmp[1] == '#')
				graph->flag = (ft_strstr(tmp, "start") || ft_strstr(tmp, "end")) ? tmp[2] : '\0';
			else if (tmp[0] == '#' && tmp[1] != '#')
			{
				if (*write == NULL)
					*write = include_comment(tmp);
				else
				{
					comm = *write;
					while (comm->next != NULL)
						comm = comm->next;
					comm->next = include_comment(tmp);
				}
			}
			if (tmp[0] == '\0')
				return (start);
			free(tmp);
			status = get_next_line(0, &tmp);
		}
		if (tmp[0] != '\0' && ft_strchr(tmp, ' '))
		{
			tmp2 = ft_strsplit(tmp, ' ');
			if (is_exist(tmp2, 0) == 0 || is_exist(tmp2, 1) == 0 || is_exist(tmp2, 2) == 0)
				return (NULL);
			graph->id = ft_strnew(ft_strlen(tmp2[0]));
			ft_strcpy(graph->id, tmp2[0]);
			graph->x = (is_exist(tmp2, 1) == 1) ? ft_atoi(tmp2[1]) : 0;
			graph->y = (is_exist(tmp2, 2) == 1) ? ft_atoi(tmp2[2]) : 0;
			graph->nbr = NULL;
			graph->visited = 0;
			graph->flag = (graph->flag != 's' && graph->flag != 'e') ? '\0' : graph->flag;
			graph->aints = (graph->flag == 's') ? res : 0;
			free(tmp);
			status = get_next_line(0, &tmp);
			delete_split(tmp2);
		}
		else
		{
			graph->next = NULL;
			graph = start;
			if (graph != NULL && graph->next != NULL)
			{
				while (graph->next->next != NULL)
					graph = graph->next;
				free(graph->next);
				graph->next = NULL;
			}
			else
			{
				free(start);
				start = NULL;
			}
		}
	}
	if (start != NULL && graph != NULL)
		graph->next = NULL;
	if (start != NULL && status == 1)
		parse_dop(&start, tmp);
	return (start);
}

void	delete_nbr(t_ptr **nbr)
{
	t_ptr	*tmp;

	while (*nbr != NULL)
	{
		tmp = (*nbr)->next;
		(*nbr)->ptr = NULL;
		free((*nbr));
		*nbr = tmp;
	}
}

void	delete_graph(t_lem **graph)
{
	t_lem	*tmp;

	while (*graph != NULL)
	{
		tmp = (*graph)->next;
		free((*graph)->id);
		(*graph)->id = NULL;
		delete_nbr(&((*graph)->nbr));
		free((*graph));
		*graph = tmp;
	}
}

void	delete_path(int **path)
{
	int		i;

	i = 0;
	while (path[i] != NULL)
	{
		free(path[i]);
		path[i] = NULL;
		i++;
	}
	free(path);
	path = NULL;
}

void	write_comments(t_comm **write, char flag)
{
	t_comm	*tmp;

	if (flag == 'w')
		ft_putstr("Comments:\n");
	while (*write != NULL)
	{
		tmp = (*write)->next;
		if (flag == 'w')
		{
			ft_putstr((*write)->comment);
			ft_putstr("\n");
		}
		free((*write)->comment);
		(*write)->comment = NULL;
		free(*write);
		*write = tmp;
	}
	*write = NULL;
}

int		main(void)
{
	t_lem	*graph;
	int		**path;
	t_lem	*tmp;
	t_comm	*write;

	path = NULL;
	write = NULL;
	if ((graph = parse(&write)) == NULL)
	{
		ft_putstr("Error\n");
		delete_graph(&graph);
		write_comments(&write, 'd');
		return (0);
	}
	if (test(graph) == 1)
	{
		ft_putstr("Error\n");
		delete_graph(&graph);
		write_comments(&write, 'd');
		return (0);
	}
	if (write != NULL)
		write_comments(&write, 'w');
	path = get_path(graph);
	if (size_line(path[0]) < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	tmp = graph;
	while (tmp->flag != 's' && tmp != NULL)
		tmp = tmp->next;
	lets_go(path, graph, tmp->aints);
	delete_graph(&graph);
	delete_path(path);
	return (0);
}
