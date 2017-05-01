/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:28:35 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/27 14:02:58 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	void	*res;

	i = 0;
	res = dst;
	while (i < n)
	{
		if (*(unsigned char*)src == (unsigned char)c)
		{
			*(unsigned char*)res++ = *(unsigned char*)src++;
			return (res);
		}
		*(unsigned char*)res++ = *(unsigned char*)src++;
		i++;
	}
	return (NULL);
}
