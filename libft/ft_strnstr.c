/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:52:38 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/25 20:52:41 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *str2, size_t len)
{
	size_t	i;
	size_t	size;
	char	*str1;

	i = 0;
	size = ft_strlen(str2);
	str1 = (char*)str;
	if (ft_strlen(str) < size)
		return (NULL);
	if (size == 0)
		return (str1);
	while (str1[i] && len && len >= size)
	{
		if (ft_strncmp(&str1[i], str2, size) == 0)
			return (&str1[i]);
		i++;
		len--;
	}
	return (0);
}
