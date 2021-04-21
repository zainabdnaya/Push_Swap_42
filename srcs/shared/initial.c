/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:46:37 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/21 03:04:20 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*initial(t_all *all)
{
	all = (t_all *)malloc(sizeof(t_all));
	if (all == NULL)
		exit(1);
	all->a = NULL;
	all->b = NULL;
	all->len = 0;
	all->line = NULL;
	all->split = NULL;
	all->print = 0;
	all->color = 0;
	return (all);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	        char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

int	condition(char *line)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "ra"))
		return (1);
	if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "sb"))
		return (1);
	if (!ft_strcmp(line, "rb") || !ft_strcmp(line, "rrb"))
		return (1);
	if (!ft_strcmp(line, "pb") || !ft_strcmp(line, "pa"))
		return (1);
	if (!ft_strcmp(line, "pa") || !ft_strcmp(line, "ss"))
		return (1);
	if (!ft_strcmp(line, "rrr") || !ft_strcmp(line, "rr"))
		return (1);
	else
		return (0);
}
