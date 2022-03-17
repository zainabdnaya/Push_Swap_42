/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_nor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:11:37 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/21 16:11:49 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_norm(t_stack **a, t_stack **b)
{
	*b = (t_stack *)malloc(sizeof(t_stack));
	(*b)->previous = NULL;
	(*b)->number = (*a)->number;
	(*b)->next = NULL;
	(*a) = (*a)->next;
	(*a)->previous = NULL;
}

void	push_stack(t_stack **a, t_stack **b, t_stack *new)
{
	new = NULL;
	if (*b == NULL && *a)
		push_norm(a, b);
	else
	{
		if (*a)
		{
			new = (t_stack *)malloc(sizeof(t_stack));
			new->number = (*a)->number;
			new->next = NULL;
			new->previous = NULL;
			add_front(b, new);
			(*a) = (*a)->next;
		}
	}
}
