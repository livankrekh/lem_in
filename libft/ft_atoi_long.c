/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:58:19 by liabanzh          #+#    #+#             */
/*   Updated: 2017/03/17 17:58:21 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	long long	conw(long long index, const char *str, long long index_copy)
{
	long long x;
	long long sum;
	long long con;

	sum = 0;
	x = 1;
	index--;
	while (index >= index_copy)
	{
		con = (str[index] - 48) * x;
		x = x * 10;
		sum = sum + con;
		index--;
	}
	if (index < 0)
		index = 0;
	if (str[index] == '-')
		sum = sum * -1;
	return (sum);
}

static	long long	check_array(const char *str)
{
	long long index;

	index = 0;
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\v' ||
		str[index] == '\f' || str[index] == '\r' || str[index] == '\n')
		index++;
	if (str[index] == '-')
		index++;
	else if (str[index] == '+')
		index++;
	return (index);
}

long long			ft_atoi_long(const char *str)
{
	long long index;
	long long sum;
	long long index_copy;

	index = check_array(str);
	index_copy = index;
	while ((str[index] >= '0') && (str[index] <= '9'))
		index++;
	sum = conw(index, str, index_copy);
	return (sum);
}
