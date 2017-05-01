/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiholkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:35:31 by aiholkin          #+#    #+#             */
/*   Updated: 2016/12/05 15:11:29 by aiholkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_realloc(char *str, int new_size)
{
	char	*fresh;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	fresh = (char*)malloc(sizeof(char) * new_size + 1);
	while (str[i] != '\0' && new_size > 0)
	{
		fresh[i] = str[i];
		i++;
		new_size--;
	}
	fresh[i] = '\0';
	free(str);
	return (fresh);
}
