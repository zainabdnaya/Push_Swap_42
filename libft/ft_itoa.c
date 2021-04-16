/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:08:32 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/08 13:55:47 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_intlen(int n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char			*myalloc(char *arr, int n, int *sign)
{
	size_t			len;

	len = ft_intlen(n);
	if (n >= 0)
	{
		if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		arr[len] = '\0';
	}
	else
	{
		if (!(arr = (char*)malloc(sizeof(char) * (len + 2))))
			return (NULL);
		*sign = 1;
		arr[0] = '-';
		arr[len + 1] = '\0';
	}
	return (arr);
}

char				*ft_itoa(int n)
{
	int							r;
	unsigned int				len;
	char						*arr;
	int							sign;

	sign = 0;
	len = ft_intlen(n);
	arr = NULL;
	arr = (char*)myalloc(arr, n, &sign);
	if (arr == NULL)
		return (NULL);
	while (0 < len)
	{
		if (n < 0)
			r = (n % 10) * (-1);
		else
			r = n % 10;
		arr[len + sign - 1] = r + '0';
		n = n / 10;
		len--;
	}
	return (arr);
}
