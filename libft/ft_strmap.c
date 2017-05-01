/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:03:30 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/28 18:03:32 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fresh;

	i = 0;
	if (s == NULL)
		return (NULL);
	fresh = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s != NULL && fresh != NULL)
	{
		while (s[i] != '\0')
		{
			fresh[i] = (*f)(s[i]);
			i++;
		}
		fresh[i] = '\0';
	}
	return (fresh);
}
