/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:11:37 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/09 03:07:45 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*firstocc(char const *s, const char *set)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i] && set[j])
	{
		if (s[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return ((char*)&s[i]);
}

static int		lastocc(char const *s, char const *set)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s);
	j--;
	while (j > 0 && set[i])
	{
		if (set[i] == s[j])
		{
			j--;
			i = 0;
		}
		else
		{
			i++;
		}
	}
	return (j);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*tmp;
	int			i;

	i = 0;
	if (!s1)
		return (NULL);
	s1 = firstocc(s1, set);
	tmp = (char *)malloc(sizeof(char) * lastocc(s1, set) + 2);
	if (tmp == NULL)
		return (NULL);
	while (i < lastocc(s1, set) + 1)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
