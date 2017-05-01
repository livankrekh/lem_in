/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:43:30 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/28 19:43:31 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		size1;
	int		size2;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	new = (char*)malloc(sizeof(char) * (size1 + size2 + 1));
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	return (new);
}
