/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:40:53 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/25 15:40:59 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	char *str_pointer;

	str_pointer = (char*)str;
	if (str == NULL)
		return (NULL);
	while (*str_pointer != (char)c && *str_pointer != '\0')
		str_pointer++;
	if (*str_pointer == (char)c)
		return (str_pointer);
	else
		return (NULL);
	return (str_pointer);
}
