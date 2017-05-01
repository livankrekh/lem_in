/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:04:12 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/28 16:04:15 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*sn1;
	unsigned char	*sn2;

	i = 0;
	sn1 = (unsigned char*)s1;
	sn2 = (unsigned char*)s2;
	while (sn1[i] == sn2[i] && sn1[i] != '\0' && sn2[i] != '\0')
		i++;
	return (sn1[i] - sn2[i]);
}
