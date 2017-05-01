/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:02:39 by liabanzh          #+#    #+#             */
/*   Updated: 2016/11/28 16:02:41 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		conw(int index, const char *str, int index_copy)
{
	int x;
	int sum;
	int con;

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

static	int		check_array(const char *str)
{
	int index;

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

int				ft_atoi(const char *str)
{
	int index;
	int sum;
	int index_copy;

	index = check_array(str);
	index_copy = index;
	while ((str[index] >= '0') && (str[index] <= '9'))
		index++;
	sum = conw(index, str, index_copy);
	return (sum);
}
