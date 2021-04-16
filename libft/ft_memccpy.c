/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:29:41 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/07 18:47:50 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, char c, size_t len)
{
	char					*c1;
	const char				*c2;

	c1 = (char *)dest;
	c2 = (const char *)src;
	while (len-- > 0)
	{
		*c1 = *c2;
		if (*c2 == c)
			return (c1 + 1);
		c2++;
		c1++;
	}
	return (NULL);
}
