/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:45:52 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/21 17:42:30 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *one, t_stack *two)
{
	int	k;

	k = one->number;
	one->number = two->number;
	two->number = k;
}

t_stack	*sort(t_stack *head)
{
	t_stack	*start;
	t_stack	*tmp2;
	t_stack	*min;

	start = NULL;
	start = head;
	tmp2 = NULL;
	min = NULL;
	while (start->next)
	{
		min = start;
		tmp2 = start->next;
		while (tmp2)
		{
			if (min->number > tmp2->number)
				min = tmp2;
			tmp2 = tmp2->next;
		}
		swap(start, min);
		start = start->next;
	}
	return (head);
}

void	checker_pars_n(t_stack **a, t_stack **b, char *line, t_stack *tmp)
{
	if (!ft_strcmp(line, "pb") && size_list(*a) > 0)
		push_stack(a, b, tmp);
	else if (!ft_strcmp(line, "pa") && size_list(*b) > 0)
		push_stack(b, a, tmp);
	else if (!ft_strcmp(line, "ss") && size_list(*b) > 1 && size_list(*a) > 1)
		ss(a, b);
	else if (!ft_strcmp(line, "rr") && size_list(*b) > 1 && size_list(*a) > 1)
		rr(a, b);
	else if (!ft_strcmp(line, "rrr") && size_list(*b) > 1 && size_list(*a) > 1)
		rrr(a, b);
}

void	checker_pars(t_stack **a, t_stack **b, char *line)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!ft_strcmp(line, "sa") && size_list(*a) > 1)
		swap_stack(a);
	else if (!ft_strcmp(line, "ra") && size_list(*a) > 1)
		r_stack(a);
	else if (!ft_strcmp(line, "rra") && size_list(*a) > 1)
		rr_stack(a, tmp);
	else if (!ft_strcmp(line, "sb") && size_list(*b) > 1)
		swap_stack(b);
	else if (!ft_strcmp(line, "rb") && size_list(*b) > 1)
		r_stack(b);
	else if (!ft_strcmp(line, "rrb") && size_list(*b) > 1)
		rr_stack(b, tmp);
	else
		checker_pars_n(a, b, line, tmp);
	free_stack(&tmp);
}
