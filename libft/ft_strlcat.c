/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:34:58 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/22 19:35:00 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t size2;
	size_t size3;

	i = 0;
	j = 0;
	size2 = ft_strlen(src);
	if (ft_strlen(dst) >= size)
		size3 = size;
	else
		size3 = ft_strlen(dst);
	while (dst[i] != '\0')
		i++;
	if (size != 0)
	{
		while (i + j < size - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
	}
	dst[i + j] = '\0';
	return (size3 + size2);
}
