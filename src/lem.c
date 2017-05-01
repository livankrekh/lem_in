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

t_lem	*get_elem(t_lem *graph, int id)
{
	while (graph != NULL)
	{
		if (graph->id == id)
			break;
		graph = graph->next;
	}
	return (graph);
}

void	parse_dop(t_lem **graph, char *tmp)
{
	t_lem	*elem1;
	t_lem	*elem2;
	t_ptr	*ptr;
	char	**tmp2;

	while (tmp)
	{
		tmp2 = ft_strsplit(tmp, '-');
		elem1 = get_elem(*graph, ft_atoi(tmp2[0]));
		elem2 = get_elem(*graph, ft_atoi(tmp2[1]));
		ptr = elem1->nbr;
		while (ptr != NULL)
			ptr = ptr->next;
		ptr = (t_ptr*)malloc(sizeof(t_ptr));
		ptr->ptr = elem2;
		ptr->next = NULL;
		free(tmp);
		tmp = NULL;
		get_next_line(0, &tmp);
	}
}

int		parse(t_lem **origin)
{
	int		res;
	char	**tmp2;
	char	*tmp;
	t_lem	*graph;

	get_next_line(0, &tmp);
	res = ft_atoi(tmp);
	graph = *origin;
	while (!ft_strchr(tmp, '-'))
	{
		free(tmp);
		get_next_line(0, &tmp);
		if (ft_strnstr(tmp, "##", 2))
		{
			graph->flag = tmp[2];
			free(tmp);
			get_next_line(0, &tmp);
		}
		if (!ft_strchr(tmp, '-'))
		{
			tmp2 = ft_strsplit(tmp, ' ');
			graph->id = ft_atoi(tmp2[0]);
			graph->x = ft_atoi(tmp2[1]);
			graph->y = ft_atoi(tmp2[2]);
			graph->nbr = NULL;
			graph->next = (t_lem*)malloc(sizeof(t_lem));
			graph = graph->next;
		}
		else
			free(graph);
	}
	graph = NULL;
	parse_dop(origin, tmp);
	return (res);
}

int		main(void)
{
	t_lem	*graph;
	int		aints;
	t_lem	*ptr2;
	t_ptr	*tmp;

	graph = (t_lem*)malloc(sizeof(t_lem));
	aints = parse(&graph);
	printf("Aints = %d\n", aints);
	while (graph != NULL)
	{
		printf("________________________________\n");
		printf("ID = %d\n", graph->id);
		printf("Flag = %c\n", graph->flag);
		printf("x = %d\n", graph->x);
		printf("y = %d\n", graph->y);
		tmp = graph->nbr;
		while (tmp != NULL)
		{
			ptr2 = tmp->ptr;
			printf("NBR_id = %d\n", ptr2->id);
			tmp = tmp->next;
		}
		graph = graph->next;
	}
	return (0);
}
