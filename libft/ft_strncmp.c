/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:36:31 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/03 01:21:38 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int						i;
	unsigned char			*str1;
	unsigned char			*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n-- > 0 && (str1[i] || str2[i]))
	{
		if (str1[i] < str2[i])
			return (str1[i] - str2[i]);
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
