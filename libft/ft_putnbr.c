/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:00:35 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/28 16:00:40 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	is_max(int n)
{
	if (n == -2147483648)
		ft_putstr("2147483648");
}

void			ft_putnbr(int n)
{
	int index_p;

	index_p = 1;
	if (n == 0)
		ft_putchar('0');
	if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
	}
	is_max(n);
	while (n / index_p > 0)
		index_p *= 10;
	index_p /= 10;
	if (n >= 1000000000)
		index_p = 1000000000;
	while (index_p > 0)
	{
		ft_putchar((char)(n / index_p) + '0');
		n -= (n / index_p * index_p);
		index_p /= 10;
	}
}
