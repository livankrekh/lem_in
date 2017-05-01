/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:13:08 by liabanzh          #+#    #+#             */
/*   Updated: 2016/12/03 17:13:13 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static	char	*is_rmax(char *res, int n)
{
	res = (char*)malloc(sizeof(char) * ((n < 0) ? 12 : 11));
	if (n < 0)
		ft_strcpy(res, "-2147483648");
	else
		ft_strcpy(res, "2147483647");
	return (res);
}

static	char	*ft_include(char *res, long index, int n)
{
	int		i;
	long	copy;

	i = (n < 0) ? 1 : 0;
	copy = (long)n;
	if (n == 0)
	{
		ft_strcpy(res, "0");
		return (res);
	}
	if (n < 0)
	{
		res[0] = '-';
		copy *= -1;
	}
	while (index > 0)
	{
		res[i] = (char)(copy / index) + '0';
		copy -= (copy / index * index);
		index /= 10;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char			*ft_itoa(int n)
{
	char	*res;
	long	index;
	long	copy;
	int		i;

	index = 1;
	i = (n == 0) ? 1 : 0;
	copy = (long)n;
	if (n < 0)
		copy *= -1;
	while (copy / index > 0 && index < 2147483647)
	{
		index *= 10;
		i++;
	}
	res = (char*)malloc(sizeof(char) * ((n < 0) ? i + 1 : i) + 1);
	if (res == NULL)
		return (NULL);
	if (n == 2147483647 || n == -2147483648)
		return (is_rmax(res, n));
	return (ft_include(res, index / 10, n));
}
