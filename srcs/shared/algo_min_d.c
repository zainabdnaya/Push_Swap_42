/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:09:10 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/20 16:07:45 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_norm_d(t_stack **a, t_stack **b, int len)
{
	s_c_display(a, b, 8);
	s_c_display(a, b, 3);
}

void	sort_a_3_d(t_stack **a, t_stack **b, int len)
{
	t_stack	*bottom1;
	    int	min;

	bottom1 = bottom(*a);
	min = get_min(*a);
	while (check_sort(a, len) == 0)
	{
		if ((*a)->number < (*a)->next->number && bottom1->number == min)
			s_c_display(a, b, 3);
		else if ((*a)->number > (*a)->next->number && bottom1->number == min)
			sort_norm_d(a, b, len);
		else if ((*a)->next->number == min)
		{
			if ((*a)->number < bottom1->number)
				s_c_display(a, b, 8);
			else if ((*a)->number > bottom1->number)
				s_c_display(a, b, 2);
		}
		else if ((*a)->number == min && (*a)->next->number > bottom1->number)
		{
			s_c_display(a, b, 8);
			s_c_display(a, b, 2);
		}
	}
}

void	sort_min1_d(t_stack **a, t_stack **b, int len)
{
	    int	size;
	    int	m;
	t_stack	*ss;
	t_stack	*tmp;

	size = len;
	while (size > 3)
	{
		m = get_min(*a);
		tmp = (*a)->next;
		if ((*a)->number != m && tmp && tmp->number == m)
			s_c_display(a, b, 8);
		while (m != (*a)->number)
			norm_part1_c(a, b, m, 0);
		if (m == (*a)->number)
		{
			ss = *a;
			s_c_display(a, b, 1);
			free(ss);
			size--;
		}
	}
}

void	sort_min_d(t_stack **a, t_stack **b, int len)
{
	t_stack	*ss;

	ss = NULL;
	if (len == 3)
		sort_a_3_d(a, b, len);
	else if (len > 3)
	{
		sort_min1_d(a, b, len);
		sort_a_3_d(a, b, 3);
		while ((*b))
		{
			ss = *b;
			s_c_display(a, b, 4);
			free(ss);
		}
		free_stack(b);
	}
	free_stack(a);
}
