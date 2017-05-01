/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:21:12 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/27 15:21:13 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*str;

	i = 0;
	str = (void*)s;
	while (i < n)
	{
		if (*(unsigned char*)str++ == (unsigned char)c)
			return ((void*)s);
		s++;
		i++;
	}
	return (NULL);
}
