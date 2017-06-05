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
		get_next_line(0, &tmp);
	}
}

t_lem	*parse()
{
	int		res;
	char	**tmp2;
	char	*tmp;
	t_lem	*start;
	t_lem	*graph;

	if (get_next_line(0, &tmp) < 1 || tmp[0] == '\n' || ft_strchr(tmp, '-') || ft_strchr(tmp, ' '))
		return (NULL);
	res = ft_atoi(tmp);
	start = NULL;
	graph = start;
	free(tmp);
	get_next_line(0, &tmp);
	while (ft_strchr(tmp, ' ') || (tmp[0] == '#'))
	{
		if (graph == NULL)
		{
			start = (t_lem*)malloc(sizeof(t_lem));
			graph = start;
		}
		else
		{
			graph->next = (t_lem*)malloc(sizeof(t_lem));
			graph = graph->next;
		}
		while (tmp[0] == '#' || tmp[0] == '\0')
		{
			if (tmp[0] == '#' && tmp[1] == '#')
				graph->flag = (ft_strstr(tmp, "start") || ft_strstr(tmp, "end")) ? tmp[2] : '\0';
			if (tmp[0] == '\0')
				return (start);
			free(tmp);
			get_next_line(0, &tmp);
		}
		if (ft_strchr(tmp, ' '))
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
			get_next_line(0, &tmp);
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
	if (start != NULL)
		parse_dop(&start, tmp);
	return (start);
}

void	print_farm(t_lem *graph)
{
	t_lem	*ptr2;
	t_ptr	*tmp;

	while (graph != NULL)
	{
		printf("________________________________\n");
		printf("ID = %s\n", graph->id);
		printf("Flag = %c\n", graph->flag);
		printf("x = %d\n", graph->x);
		printf("y = %d\n", graph->y);
		printf("IDE = %d\n", graph->ide);
		tmp = graph->nbr;
		while (tmp != NULL)
		{
			ptr2 = tmp->ptr;
			printf("NBR_id = %s\n", ptr2->id);
			tmp = tmp->next;
		}
		graph = graph->next;
	}
}

int		main(void)
{
	t_lem	*graph;
	int		**path;
	t_lem	*tmp;

	path = NULL;
	if ((graph = parse()) == NULL)
	{
		ft_putstr("Error\n");
		return (0);
	}
	//print_farm(graph);
	if (test(graph) == 1)
		ft_putstr("Error\n");
	else
	{
		ft_putstr("OK\n");
		path = get_path(graph);
		tmp = graph;
		while (tmp->flag != 's' && tmp != NULL)
			tmp = tmp->next;
		lets_go(path, graph, tmp->aints);
	}
	return (0);
}
