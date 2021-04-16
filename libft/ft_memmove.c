/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:29:00 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/11 15:37:15 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char					*d;
	const char				*s;

	s = (char *)src;
	d = (char *)dest;
	if (!s && !d)
		return (NULL);
	if (s == d)
		return (dest);
	if (s < d)
	{
		s = src + n - 1;
		d = dest + n - 1;
		while (n-- > 0)
			*d-- = *s--;
	}
	else
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	return (dest);
}
