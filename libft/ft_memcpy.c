/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:10:17 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/22 14:10:20 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	void	*res;

	i = 0;
	res = dst;
	while (i < n)
	{
		*(unsigned char*)res++ = *(unsigned char*)src++;
		i++;
	}
	return (dst);
}
