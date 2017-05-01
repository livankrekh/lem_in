/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:10:01 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 19:35:09 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)));
}

int			ft_atoi_base(const char *str, int base)
{
	int	value;
	int	sign;

	value = 0;
	if (base <= 1 || base > 36)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_inbase(*str, base))
	{
		if (*str - 'a' >= 0)
			value = value * base + (*str - 'a' + 10);
		else if (*str - 'A' >= 0)
			value = value * base + (*str - 'A' + 10);
		else
			value = value * base + (*str - '0');
		str++;
	}
	return (value * sign);
}
