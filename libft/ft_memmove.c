/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:17:05 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/28 17:17:07 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void	*dstc;

	dstc = dst;
	if (dst > src && n != 0)
	{
		dstc += n - 1;
		src += n - 1;
		while (n)
		{
			*(unsigned char*)dstc = *(unsigned char*)src;
			dstc--;
			src--;
			n--;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dstc, src, n));
	return (dst);
}
