/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:59:39 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/17 03:03:22 by zainabdnaya      ###   ########.fr       */
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
    free_stack(&tmp2);
}

t_stack *rr_part1(t_stack *head, t_stack *tmp)
{
    while (head->next)
        head = head->next;
    tmp->number = head->number;
    tmp->next = NULL;
    tmp->previous = NULL;

    return (tmp);
}

void rr_stack(t_stack **head, t_stack *tmp)
{
    t_stack *new_node;
    t_stack *a;

    a = *head;
    if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
        return;
    tmp = rr_part1(*head, tmp);
    while ((*head))
    {
        if ((*head)->next->next == NULL)
            break;
        *head = (*head)->next;
    }
    (*head)->next = NULL;
    *head = a;
    head = add_front(head, tmp);
}

void push_stack(t_stack **a, t_stack **b,t_stack *new)
{
    // t_stack *new;
    t_stack **tmp;

    new = NULL;
    tmp = NULL;
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
            new = (t_stack *)malloc(sizeof(t_stack));
            new->number = (*a)->number;
            new->next = NULL;
            new->previous = NULL;
            tmp = (b);
            b = add_front(tmp, new);
            (*a) = (*a)->next;
            // print_list(new);
            // while ((*b)->previous != NULL)
            //     (*b) = (*b)->previous;
            // (*b) = new;
            // new->next = (tmp);
            // new->previous = NULL;
            // free(new);
            // new = NULL;
        }
    }
}