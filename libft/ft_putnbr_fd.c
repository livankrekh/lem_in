/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:27:24 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/28 16:27:25 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	is_max_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("2147483648", fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	int index_p;

	index_p = 1;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
	}
	is_max_fd(n, fd);
	while (n / index_p > 0)
		index_p *= 10;
	index_p /= 10;
	if (n >= 1000000000)
		index_p = 1000000000;
	while (index_p > 0)
	{
		ft_putchar_fd((char)(n / index_p) + '0', fd);
		n -= (n / index_p * index_p);
		index_p /= 10;
	}
}
