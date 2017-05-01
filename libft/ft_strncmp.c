/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:04:42 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/28 16:04:43 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*sn1;
	unsigned char	*sn2;

	sn1 = (unsigned char*)s1;
	sn2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while ((*sn1 == *sn2 && n > 1))
	{
		if (*sn1 == '\0' || *sn2 == '\0')
			return (*sn1 - *sn2);
		n--;
		sn1++;
		sn2++;
	}
	return (*sn1 - *sn2);
}
