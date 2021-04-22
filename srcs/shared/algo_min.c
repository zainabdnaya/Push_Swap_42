/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:08:38 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/22 00:08:42 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_norm_3(t_stack **a, t_stack **b, t_all *all)
{
	switch_case(a, b, 8, all);
	switch_case(a, b, 3, all);
}

void	sort_a_3(t_stack **a, t_stack **b, int len, t_all *all)
{
	t_stack	*bottom1;
	    int	min;

	bottom1 = bottom(*a);
	min = get_min(*a);
	while (check_sort(a, len) == 0)
	{
		if ((*a)->number < (*a)->next->number && bottom1->number == min)
			switch_case(a, b, 3, all);
		else if ((*a)->number > (*a)->next->number && bottom1->number == min)
			sort_norm_3(a, b, all);
		else if ((*a)->next->number == min)
		{
			if ((*a)->number < bottom1->number)
				switch_case(a, b, 8, all);
			else if ((*a)->number > bottom1->number)
				switch_case(a, b, 2, all);
		}
		else if ((*a)->number == min && (*a)->next->number > bottom1->number)
		{
			switch_case(a, b, 8, all);
			switch_case(a, b, 2, all);
		}
	}
}

void	sort_min1(t_stack **a, t_stack **b, int len, t_all *all)
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
			switch_case(a, b, 8, all);
		while (m != (*a)->number)
			norm_part1(a, b, all, m);
		if (m == (*a)->number)
		{
			ss = *a;
			switch_case(a, b, 1, all);
			free(ss);
			size--;
		}
	}
}

void	sort_min(t_stack **a, t_stack **b, int len, t_all *all)
{
	t_stack	*ss;

	ss = NULL;
	if (len == 2 && (*a)->number > (*a)->next->number)
			switch_case(a, b, 8, all);
	if (len < 3)
		sort_a_3(a, b, len, all);
	else if (len > 3)
	{
		sort_min1(a, b, len, all);
		sort_a_3(a, b, 3, all);
		while ((*b))
		{
			ss = *b;
			switch_case(a, b, 4, all);
			free(ss);
		}
		free_stack(b);
	}
	free_stack(a);
}
