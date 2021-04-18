/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:34:50 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/08 13:37:23 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	operation(const char *str, long lenght, int sign)
{
	long		r;
	int			i;

	r = 0;
	i = 0;
	while (str[lenght] >= 48 && str[lenght] <= 57)
	{
		r = r * 10 + str[lenght] - '0';
		lenght++;
		i++;
	}
	if (i > 19)
	{
		if (sign > 0)
			return (-1);
		else
			return (0);
	}
	return (sign * r);
}

int			ft_atoi(const char *str)
{
	long		lenght;
	int			sign;

	lenght = 0;
	sign = 1;
	while (str[lenght] == ' ' || str[lenght] == '\n' || str[lenght] == '\t'
			|| str[lenght] == '\r' || str[lenght] == '\f'
			|| str[lenght] == '\v')
		lenght++;
	if (str[lenght] == '-' || str[lenght] == '+')
	{
		if (str[lenght] == '-')
			sign *= -1;
		lenght++;
	}
	return (operation(str, lenght, sign));
}
