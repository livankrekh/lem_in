/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:17:33 by liabanzh          #+#    #+#             */
/*   Updated: 2016/12/09 20:17:35 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_change(char **s, char old_c, char new_c)
{
	int i;
	int j;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != NULL)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] == old_c)
				s[i][j] = new_c;
			j++;
		}
		i++;
	}
	return (s);
}
