/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderby.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:47:46 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/21 01:17:57 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **a, t_stack **b)
{
	r_stack(a);
	r_stack(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = NULL;
	rr_stack(a, tmp);
	rr_stack(b, tmp);
}

int	avreage(t_stack *a)
{
	    int	k;
	    int	i;
	    int	avg;
	t_stack	*tmp;

	i = 0;
	k = 0;
	avg = 0;
	tmp = a;
	while (a != NULL)
	{
		k += a->number;
		i++;
		a = a->next;
	}
	a = tmp;
	avg = (int)(k / i);
	return (avg);
}

char	**normal(t_all *all, int ac, char **av)
{
	if (ac == 2)
		all->split = ft_split(av[1], ' ');
	else
		all->split = &av[1];
	return (all->split);
}
