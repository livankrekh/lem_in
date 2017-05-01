/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:05:51 by liabanzh          #+#    #+#             */
/*   Updated: 2017/01/12 14:05:53 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void		ft_realloc_l(char **s1)
{
	char	*fresh;
	int		i;

	i = ft_strlen(*s1);
	fresh = ft_strnew(i);
	ft_strncpy(fresh, *s1, i);
	free(*s1);
	*s1 = ft_strnew(i + BUFF_SIZE);
	ft_strncpy(*s1, fresh, i);
	free(fresh);
}

static	t_fdlist	*list_control(int fd, t_fdlist *begin)
{
	t_fdlist	*tmp;
	t_fdlist	*current;

	if (!(begin))
	{
		begin = (t_fdlist*)malloc(sizeof(*begin));
		begin->fd = fd;
		begin->next = NULL;
		begin->buf = NULL;
		return (begin);
	}
	current = begin;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		tmp = current;
		current = current->next;
	}
	current = (t_fdlist*)malloc(sizeof(*current));
	tmp->next = current;
	current->next = NULL;
	current->fd = fd;
	current->buf = NULL;
	return (current);
}

static	char		*read_file(int fd, char **buf)
{
	char	*tmp;
	int		res;

	res = 0;
	if ((tmp = ft_strnew(BUFF_SIZE)) == NULL)
		return (NULL);
	ft_strclr(tmp);
	while ((res = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[res] = '\0';
		ft_realloc_l(buf);
		ft_strncat(*buf, tmp, res);
		if (ft_strchr(*buf, '\n') != NULL)
			break ;
		ft_strdel(&tmp);
		tmp = ft_strnew(BUFF_SIZE);
	}
	free(tmp);
	return (*buf);
}

static	char		*include_line(char **buf, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*buf)[i] != '\n' && (*buf)[i] != '\0')
		i++;
	if (i == 0 && (*buf)[i] == '\0')
		return (NULL);
	tmp = ft_strnew(ft_strlen(*buf) - i);
	*line = ft_strnew(i);
	ft_strncpy(*line, *buf, i);
	ft_strncpy(tmp, &(*buf)[i + 1], ft_strlen(&(*buf)[i + 1]));
	ft_strclr(*buf);
	ft_strncpy(*buf, tmp, ft_strlen(tmp));
	free(tmp);
	tmp = 0;
	return (*buf);
}

int					get_next_line(const int fd, char **line)
{
	static	t_fdlist	*begin = NULL;
	t_fdlist			*current;
	char				*test[BUFF_SIZE + 1];

	current = NULL;
	if (fd < 0 || read(fd, test, 0) == -1)
		return (-1);
	if (!(begin))
		begin = list_control(fd, begin);
	current = list_control(fd, begin);
	if (read_file(fd, &(current->buf)) == NULL)
		return (0);
	if (include_line(&(current->buf), line) == NULL)
		return (0);
	return (1);
}
