/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:59:39 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/20 16:11:18 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **head)
{
	    int	k;
	    int	l;
	t_stack	*tmp;

	tmp = NULL;
	if ((*head) && (*head)->next)
	{
		tmp = *head;
		k = (*head)->number;
		l = (*head)->next->number;
		tmp = *head;
		(*head)->number = l;
		tmp = *head;
		(*head)->next->number = k;
		(*head) = tmp;
	}
}

void	r_stack(t_stack **head)
{
	if (*head)
	{
		*head = (*head)->next;
		add_back1(head);
	}
}

t_stack	*rr_part1(t_stack *head, t_stack *tmp)
{
	while (head->next)
		head = head->next;
	tmp->number = head->number;
	tmp->next = NULL;
	tmp->previous = NULL;
	return (tmp);
}

void	botom(t_stack **head)
{
	while ((*head))
	{
		if ((*head)->next->next == NULL)
			break ;
		*head = (*head)->next;
	}
	free((*head)->next);
	(*head)->next = NULL;
}

void	rr_stack(t_stack **head, t_stack *tmp)
{
	t_stack	*a;

	a = NULL;
	tmp = NULL;
	if (*head)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (tmp == NULL)
			return ;
		tmp = rr_part1(*head, tmp);
		a = *head;
		botom(head);
		*head = a;
		add_front(head, tmp);
	}
}
