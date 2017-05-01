/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:28:27 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/28 19:28:30 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	sub = (char*)malloc(sizeof(char) * len + 1);
	if (sub == NULL || s == NULL)
		return (NULL);
	ft_strncpy(sub, &s[start], len);
	sub[len] = '\0';
	return (sub);
}
