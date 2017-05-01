/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:10:06 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/26 19:10:08 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	void	*res;

	i = 0;
	res = b;
	while (i < len)
	{
		*(unsigned char*)res++ = (unsigned char)c;
		i++;
	}
	return (b);
}
