/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_most_visible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 21:58:08 by liabanzh          #+#    #+#             */
/*   Updated: 2016/12/09 21:58:10 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		count(char *str, char c)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			res++;
		i++;
	}
	return (res);
}

char			ft_most_visible(char *str)
{
	char	res;
	int		i;
	int		max;

	i = 0;
	res = str[0];
	max = 0;
	while (str[i] != '\0')
	{
		if (count(str, str[i]) > max)
		{
			max = count(str, str[i]);
			res = str[i];
		}
		i++;
	}
	return (res);
}
