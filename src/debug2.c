/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:36:22 by liabanzh          #+#    #+#             */
/*   Updated: 2017/07/14 18:36:25 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem.h"

int		gnl_mod(int fd, char **tmp, t_comm **write)
{
	t_comm	*tmp_comm;
	int		status;

	tmp_comm = *write;
	if ((status = get_next_line(fd, tmp)) <= 0)
		return (status);
	if (*write == NULL)
	{
		*write = (t_comm*)malloc(sizeof(t_comm));
		(*write)->comment = ft_strnew(ft_strlen(*tmp));
		ft_strncpy((*write)->comment, *tmp, ft_strlen(*tmp));
		(*write)->flag = 'm';
		(*write)->next = NULL;
	}
	else
	{
		while (tmp_comm->next != NULL)
			tmp_comm = tmp_comm->next;
		tmp_comm->next = (t_comm*)malloc(sizeof(t_comm));
		tmp_comm->next->comment = ft_strnew(ft_strlen(*tmp));
		ft_strncpy(tmp_comm->next->comment, *tmp, ft_strlen(*tmp));
		tmp_comm->next->flag = 'm';
		tmp_comm->next->next = NULL;
	}
	return (status);
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

void	mem_debug(t_comm **write, char **tmp)
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
}
