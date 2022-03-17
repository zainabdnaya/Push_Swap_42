/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:06:00 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/20 14:19:34 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	part1_1(t_stack **a, t_stack **b, int len, t_all *all)
{
	   int	size;
	   int	m;
	t_stack	*tmp;
	t_stack	*tmps;

	size = len;
	while (size >= val_aprox(len / 4))
	{
		tmps = dup_list(*a);
		m = get_pivot(tmps);
		while (check_under_pivot((*a), m) && (*a))
		{
			if ((*a)->number <= m)
			{
				tmp = *a;
				switch_case(a, b, 1, all);
				size--;
				free(tmp);
			}
			else
				norm_part1(a, b, all, m);
		}
		free_stack(&tmps);
	}
}

void	part1_2(t_stack **a, t_stack **b, t_all *all, int size)
{
	    int	min;
	t_stack	*tmp;

	tmp = NULL;
	while (*a && !check_sort(a, size))
	{
		min = get_min(*a);
		tmp = (*a)->next;
		while ((*a)->number != min && tmp && tmp->number == min)
			switch_case(a, b, 8, all);
		while (size_list(*a) && check_under_pivot((*a), min))
		{
			if ((*a)->number == min)
			{
				tmp = *a;
				switch_case(a, b, 1, all);
				free(tmp);
				size--;
			}
			else
				norm_part1(a, b, all, min);
		}
	}
}

void	part1_3(t_stack **a, t_stack **b, t_all *all, int max)
{
	t_stack	*tmp;

	tmp = NULL;
	while (*b)
	{
		max = get_max(*b);
		while (check_upper_pivot((*b), max))
		{
			max = get_max(*b);
			tmp = (*b)->next;
			while ((*b)->number != max && tmp && tmp->number == max)
				switch_case(a, b, 7, all);
			while (((*b)->number != max) && *b)
				norm_part3(a, b, all, max);
			while (*b && (*b)->number == max)
			{
				tmp = *b;
				switch_case(a, b, 4, all);
				max = get_max(*b);
				free(tmp);
			}
		}
	}
}

void	algo_1(t_stack **a, t_stack **b, int len, t_all *all)
{
	int	m;

	m = 0;
	part1_1(a, b, len, all);
	part1_2(a, b, all, len);
	part1_3(a, b, all, m);
	free_stack(a);
	free_stack(b);
}
