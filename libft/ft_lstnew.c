/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:10:08 by liabanzh          #+#    #+#             */
/*   Updated: 2016/12/09 13:10:09 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nlst;

	if ((nlst = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		nlst->content_size = 0;
		nlst->content = NULL;
	}
	else
	{
		if ((nlst->content = malloc(sizeof(content))) == NULL)
			return (NULL);
		nlst->content = ft_memcpy(nlst->content, content, content_size);
		nlst->content_size = content_size;
	}
	nlst->next = NULL;
	return (nlst);
}
