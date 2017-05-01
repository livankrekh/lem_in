/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:08:00 by liabanzh          #+#    #+#             */
/*   Updated: 2016/12/09 13:08:02 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmplst;
	t_list	*nxtlst;

	tmplst = *alst;
	while (tmplst)
	{
		nxtlst = tmplst->next;
		del(tmplst->content, tmplst->content_size);
		free(tmplst);
		tmplst = nxtlst;
	}
	*alst = NULL;
}
