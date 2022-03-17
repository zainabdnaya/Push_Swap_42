/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 06:49:20 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/20 23:35:03 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	option_v(t_all *all, int ac, char **av)
{
	if (ac == 3)
		all->split = ft_split(av[2], ' ');
	else
		all->split = &av[2];
	all = fill_in(all);
	while (1)
	{
		all->line = ft_calloc(BUFFER_SIZE, sizeof(char));
		read(0, all->line, BUFFER_SIZE);
		if (all->line[0] == '\0' || all->line[0] == '\n')
		{
			checker_sort(all);
			exit(1);
		}
		else
			checker_pars_v(&all->a, &all->b, all->line);
		system("clear");
		print_all(all->a, all->b);
		free_arg(&(all->line));
	}
	if (all->line[0] == '\0' || all->line[0] == '\n')
	{
		checker_sort(all);
		exit(1);
	}
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	 int	i;

	i = 0;
	while (src[i])
		i++;
	dup = (char *)malloc(sizeof(char) * i + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*ft_calloc(size_t count, size_t size)
{
	 int	i;
	char	*ptr;

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

int	ft_strlen(char *s1)
{
	int	k;

	k = 0;
	while (s1[k])
		k++;
	return (k);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	        char	*s3;
	        char	*str1;
	        char	*str2;
	unsigned int	len;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	str1 = (char *)s1;
	str2 = (char *)s2;
	len = 0;
	s3 = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (s3 == NULL)
		return (NULL);
	while (*str1)
		s3[len++] = *(str1++);
	while (*str2)
		s3[len++] = *(str2++);
	s3[len] = '\0';
	return (s3);
}
