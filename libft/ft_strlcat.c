/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 23:00:32 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/11 22:52:39 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	j = ft_strlen(src);
	if (!dest)
		return (j);
	i = ft_strlen(dest);
	if (size <= i)
		return (size + j);
	size = size - i;
	while (*dest)
		dest++;
	while (size > 1 && *src)
	{
		*dest = *src;
		src++;
		dest++;
		size--;
	}
	*dest = '\0';
	return (i + j);
}
