/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:59:39 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/09 17:48:06 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_2_stack(t_stack *ptr, t_stack *ptr1);
void print_list(t_stack *ptr);

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

    if (*head)
    {
        tmp2 = NULL;
        tmp2 = (t_stack *)malloc(sizeof(t_stack));
        tmp2->number = (*head)->number;
        tmp2->next = NULL;
        tmp2->previous = NULL;
        (*head) = (*head)->next;
        add_back1(&(*head), tmp2);
    }
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
t_stack *rr_part2(t_stack *head)
{
    t_stack *a;

    a = head;
    while (head->next)
        head = head->next;
    // print_list(head->previous);
    head = head->previous;
    // print_list(a);
    head->next = NULL;
    head = a;
    return (head);
}

void rr_stack(t_stack **head)
{
    t_stack *tmp;
    t_stack *new_node;
    t_stack *a;

    a = (t_stack *)malloc(sizeof(t_stack));
    tmp = rr_part1(*head);
    a = rr_part2(*head);
    // *head = a;
    new_node = (t_stack *)malloc(sizeof(t_stack));
    new_node->number = tmp->number;
    new_node->next = a;
    new_node->previous = NULL;
    (*head)->previous = new_node;
    (*head) = new_node;
    free_stack(&tmp);
}

void push_stack(t_stack **a, t_stack **b)
{
    t_stack *new;
    t_stack *tmp;

    if (*b== NULL && *a)
    {
        *b= (t_stack *)malloc(sizeof(t_stack));
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

void rr(t_stack **a, t_stack **b)
{
    r_stack(a);
    r_stack(b);
}

void ss(t_stack **a, t_stack **b)
{
    swap_stack(a);
    swap_stack(b);
}

void rrr(t_stack **a, t_stack **b)
{
    // puts("here");
    rr_stack(a);
    rr_stack(b);
}