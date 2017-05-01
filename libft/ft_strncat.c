/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:08:51 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/22 19:09:00 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *destptr, const char *srcptr, size_t n)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (destptr[i] != '\0')
		i++;
	while (j < n && srcptr[j])
	{
		destptr[i + j] = srcptr[j];
		j++;
	}
	destptr[i + j] = '\0';
	return (destptr);
}
