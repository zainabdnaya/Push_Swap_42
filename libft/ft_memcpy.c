/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:39:49 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/11 12:27:17 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t		i;
	char		*c1;
	const char	*c2;

	i = 0;
	c1 = (char *)str1;
	c2 = (char *)str2;
	if (!c1 && !c2)
		return (NULL);
	if (c1 == c2)
		return (c1);
	while (i < n)
	{
		c1[i] = c2[i];
		i++;
	}
	return (c1);
}
