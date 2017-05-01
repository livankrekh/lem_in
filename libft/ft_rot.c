/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 21:31:51 by liabanzh          #+#    #+#             */
/*   Updated: 2016/12/09 21:31:53 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot(char *str, unsigned int rot)
{
	int i;
	int	diff;

	i = 0;
	diff = (int)(rot % 26);
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			if (str[i] + diff > 90)
				str[i] = ((str[i] + diff) % 90) + 64;
			else
				str[i] += diff;
		}
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (str[i] + diff > 122)
				str[i] = ((str[i] + diff) % 122) + 96;
			else
				str[i] += diff;
		}
		i++;
	}
	return (str);
}
