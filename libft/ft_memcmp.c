/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:25:41 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/08 13:55:29 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char			*src;
	unsigned char			*dst;

	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (src == dst || n == 0)
		return (0);
	else
	{
		while (n-- > 0)
		{
			if (*src != *dst)
				return (*dst - *src);
			dst++;
			src++;
		}
	}
	return (0);
}
