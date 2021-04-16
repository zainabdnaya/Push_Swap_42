/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:13:18 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/11 15:39:57 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			n;

	n = ft_strlen(s);
	while (n >= 0)
	{
		if (s[n] == c)
			return ((char*)s + n);
		n--;
	}
	return (NULL);
}
