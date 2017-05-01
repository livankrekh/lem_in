/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:06:12 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/28 16:06:13 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *str2)
{
	int		i;
	int		i_local;
	int		size;
	char	*str1;

	i = 0;
	i_local = 0;
	size = 0;
	str1 = (char*)str;
	while (str2[size] != '\0')
		size++;
	if (size == 0)
		return (str1);
	while (str1[i] != '\0')
	{
		while (str2[i_local] == str1[i + i_local])
		{
			if (i_local == size - 1)
				return (str1 + i);
			i_local++;
		}
		i_local = 0;
		i++;
	}
	return (0);
}
