/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:30:53 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/25 16:30:54 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	char *str_pointer;

	str_pointer = (char*)str;
	while (*str_pointer != '\0')
		str_pointer++;
	while (*str_pointer != (char)c && *str_pointer != *str--)
		str_pointer--;
	if (*str_pointer == (char)c)
		return (str_pointer);
	else
		return (NULL);
	return (str_pointer);
}
