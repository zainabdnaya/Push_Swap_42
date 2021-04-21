/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_ko.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:45:25 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/21 17:39:00 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*fill_in(t_all *all)
{
	t_stack	*new;

	new = NULL;
	check_replicat(all->split);
	check_ascii(all->split);
	all->a = put_in_list(all, all->split, new);
	all->len = size_list(all->a);
	return (all);
}

void	checker_sort(t_all *all)
{
	if (check_sort(&all->a, all->len) == 1)
	{
		free_stack(&all->a);
		free_stack(&all->b);
		free(all);
		all = NULL;
		ft_putstr_fd("OK\n", 1);
	}
	else
	{
		free_stack(&all->a);
		free_stack(&all->b);
		free(all);
		all = NULL;
		ft_putstr_fd("KO\n", 1);
	}
}

int	check_sort(t_stack **a, int len)
{
	t_stack	*tmp;

	// if (size_list(*a) != len)
	// 	return (0);
	(void)len;
	tmp = (*a);
	while (tmp && tmp->next)
	{
		if ((tmp)->next != NULL && ((tmp)->number < (tmp)->next->number))
			(tmp) = (tmp)->next;
		else
			return (0);
	}
	return (1);
}
