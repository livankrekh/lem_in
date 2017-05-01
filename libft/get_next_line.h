/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:02:49 by liabanzh          #+#    #+#             */
/*   Updated: 2016/12/30 15:02:50 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef	struct				s_fdlist
{
	char					*buf;
	int						fd;
	struct s_fdlist			*next;
}							t_fdlist;

int							get_next_line(const int fd, char **line);

#endif
