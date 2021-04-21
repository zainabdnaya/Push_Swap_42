/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:46:37 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/20 16:07:33 by zdnaya           ###   ########.fr       */
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
