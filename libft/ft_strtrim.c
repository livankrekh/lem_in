/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:34:52 by liabanzh          #+#    #+#             */
/*   Updated: 2016/12/02 17:34:55 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i1;
	size_t	i2;
	size_t	size;

	i1 = 0;
	i2 = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	while (s[i1] == ' ' || s[i1] == '\n' || s[i1] == '\t')
		i1++;
	if (size == i1)
		return (ft_strnew(0));
	while (s[size - i2 - 1] == ' ' || s[size - i2 - 1] == '\n'
		|| s[size - i2 - 1] == '\t')
		i2++;
	new = (char*)malloc(sizeof(char) * (size - i1 - i2) + 1);
	if (new == NULL)
		return (NULL);
	ft_strncpy(new, &s[i1], size - i1 - i2);
	new[size - i1 - i2] = '\0';
	return (new);
}
