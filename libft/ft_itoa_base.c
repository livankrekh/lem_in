/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:37:29 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/17 14:23:51 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa_base(long long int n, int base)
{
	char				*ret;
	long long int		temp_n;
	size_t				size_ret;
	char				sign;

	sign = (n < 0) ? -1 : 1;
	size_ret = 2 + (n < 0 && base == 10);
	temp_n = n;
	while ((n = n / base))
		size_ret++;
	n = temp_n;
	if ((ret = (char *)malloc(sizeof(char) * size_ret--)) == NULL)
		return (NULL);
	ret[size_ret--] = '\0';
	ret[size_ret--] = (sign * (n % base) + '0' > '9') ?
						sign * (n % base) + 'a' - 10 : sign * (n % base) + '0';
	while ((n = n / base))
		ret[size_ret--] = (sign * (n % base) + '0' > '9') ?
						sign * (n % base) + 'a' - 10 : sign * (n % base) + '0';
	if (sign < 0 && base == 10)
		ret[size_ret] = '-';
	return (ret);
}

char	*ft_itoa_base_u(uintmax_t n, int base)
{
	char				*ret;
	long long int		temp_n;
	size_t				size_ret;
	int					sign;

	sign = 1;
	size_ret = 2;
	temp_n = n;
	while ((n = n / base))
		size_ret++;
	n = temp_n;
	if ((ret = (char *)malloc(sizeof(char) * size_ret--)) == NULL)
		return (NULL);
	ret[size_ret--] = '\0';
	ret[size_ret--] = (sign * (n % base) + '0' > '9') ?
						sign * (n % base) + 'a' - 10 : sign * (n % base) + '0';
	while ((n = n / base))
		ret[size_ret--] = (sign * (n % base) + '0' > '9') ?
						sign * (n % base) + 'a' - 10 : sign * (n % base) + '0';
	return (ret);
}
