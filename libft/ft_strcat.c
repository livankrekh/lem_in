/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:19:47 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/22 18:19:49 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destptr, const char *srcptr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (srcptr == NULL || ft_strlen(srcptr) == 0)
		return (destptr);
	while (destptr[i] != '\0')
		i++;
	while (srcptr[j] != 0)
	{
		destptr[i + j] = srcptr[j];
		j++;
	}
	destptr[i + j] = '\0';
	return (destptr);
}
