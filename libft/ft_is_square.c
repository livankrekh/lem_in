/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:05:17 by liabanzh          #+#    #+#             */
/*   Updated: 2016/12/09 20:05:18 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_square(int result)
{
	int	number;

	number = 0;
	if (result < 1)
		return (-1);
	if (result == 1)
		return (0);
	while (result / 2 >= number)
	{
		if (number * number == result)
			return (number);
		number++;
	}
	return (-1);
}
