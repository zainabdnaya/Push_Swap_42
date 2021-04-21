/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:21:25 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/08 20:07:37 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int				i;
	char			*ptr;

	i = 0;
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = (size * count) - 1;
	while (i >= 0)
	{
		ptr[i] = '\0';
		i--;
	}
	return (ptr);
}
