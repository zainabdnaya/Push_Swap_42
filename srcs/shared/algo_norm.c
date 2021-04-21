/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:41:24 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/20 16:07:47 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm_part1(t_stack **a, t_stack **b, t_all *all, int m)
{
	int	index;
	int	proximity;

	index = get_index((*a), m);
	proximity = (size_list((*a)) / 2);
	if (proximity > index)
		switch_case(a, b, 2, all);
	else
		switch_case(a, b, 3, all);
}

void	norm_part3(t_stack **a, t_stack **b, t_all *all, int max)
{
	int	index;
	int	proximity;

	index = get_index_max((*b), max);
	proximity = val_aprox((size_list((*b)) / 2));
	if (proximity > index && *b)
		switch_case(a, b, 5, all);
	else if (*b)
		switch_case(a, b, 6, all);
}

t_stack	*bottom(t_stack *a)
{
	t_stack	*bottom;

	bottom = a;
	while ((bottom)->next)
		(bottom) = (bottom)->next;
	return (bottom);
}

void	norm_part1_c(t_stack **a, t_stack **b, int m, int k)
{
	int	index;
	inT	proximity;

	index = get_index((*a), m);
	proximity = (size_list((*a)) / 2);
	if (k == 1)
	{
		if (proximity > index)
			switch_case_color(a, b, 2);
		else
			switch_case_color(a, b, 3);
	}
	else
	{
		if (proximity > index)
			s_c_display(a, b, 2);
		else
			s_c_display(a, b, 3);
	}
}

void	norm_part3_c(t_stack **a, t_stack **b, int max, int k)
{
	int	index;
	int	proximity;

	index = get_index_max((*b), max);
	proximity = val_aprox((size_list((*b)) / 2));
	if (k == 1)
	{
		if (proximity > index && *b)
			switch_case_color(a, b, 5);
		else if (*b)
			switch_case_color(a, b, 6);
	}
	else
	{
		if (proximity > index && *b)
			s_c_display(a, b, 5);
		else if (*b)
			s_c_display(a, b, 6);
	}
}
