/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:40:39 by liabanzh          #+#    #+#             */
/*   Updated: 2017/03/06 14:40:41 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_toupper(const char *str)
{
	char	*res;
	int		i;

	res = ft_strnew(ft_strlen(str));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		res[i] = ft_toupper(str[i]);
		i++;
	}
	return (res);
}
