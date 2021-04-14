/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:59:39 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/14 17:00:59 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_stack(t_stack **head)
{
    int k;
    int l;
    t_stack *tmp = NULL;

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

void r_stack(t_stack **head)
{
    t_stack *tmp2;
    int k;
    tmp2 = NULL;
    if (*head)
    {
        k = (*head)->number;
        *head = (*head)->next;
        add_back1(head, tmp2, k);
    }
    else
        return;

}

t_stack *rr_part1(t_stack *head)
{
    t_stack *tmp;

    tmp = (t_stack *)malloc(sizeof(t_stack));
    while (head->next)
        head = head->next;
    tmp->number = head->number;
    tmp->next = NULL;
    tmp->previous = NULL;

    return (tmp);
}

void rr_stack(t_stack **head)
{
    t_stack *tmp;
    t_stack *new_node;
    t_stack *a;

    a = *head;
    tmp = rr_part1(*head);
    while ((*head))
    {
        if ((*head)->next->next == NULL)
            break;
        *head = (*head)->next;
    }
    (*head)->next = NULL;
    *head = a;
    add_front(head, tmp);
    // free_stack(&tmp);
}

void push_stack(t_stack **a, t_stack **b)
{
    t_stack *new;
    t_stack *tmp;

    if (*b == NULL && *a)
    {
        *b = (t_stack *)malloc(sizeof(t_stack));
        (*b)->previous = NULL;
        (*b)->number = (*a)->number;
        (*b)->next = NULL;
        (*a) = (*a)->next;
        (*a)->previous = NULL;
    }
    else
    {
        if (*a)
        {
            new = malloc(sizeof(t_stack));
            new->number = (*a)->number;
            new->next = NULL;
            new->previous = NULL;
            (*a) = (*a)->next;
            tmp = (*b);
            while ((*b)->previous != NULL)
                (*b) = (*b)->previous;
            (*b) = new;
            new->next = (tmp);
            new->previous = NULL;
        }
        else
            return;
    }
}
