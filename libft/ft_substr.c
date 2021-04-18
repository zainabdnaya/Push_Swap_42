/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:51:18 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/11 15:36:34 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*string2;
	size_t		j;

	j = 0;
	if (!s)
		return (ft_strdup(""));
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	string2 = (char*)malloc((len + 1) * sizeof(char));
	if (string2 == NULL)
		return (NULL);
	j = 0;
	while (s[start + j] && j < len)
	{
		string2[j] = (char)s[start + j];
		j++;
	}
	string2[j] = '\0';
	return (string2);
}
