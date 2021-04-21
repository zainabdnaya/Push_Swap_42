/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:21:02 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/02 14:20:25 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *str, int c, size_t n)
{
	int						i;
	unsigned char			*s;

	s = (unsigned char *)str;
	i = 0;
	while (n > 0)
	{
		s[i] = c;
		n--;
		i++;
	}
	return (str);
}
