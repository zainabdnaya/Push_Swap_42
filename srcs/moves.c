/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:59:39 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/04 15:23:40 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_2_stack(t_stack *ptr, t_stack *ptr1);
void print_list(t_stack *ptr);

t_stack *swap_stack(t_stack *head)
{
    int k;
    t_stack *swap;

    swap = head->next;

    k = head->number;

    head->number = swap->number;

    swap->number = k;

    return (head);
}

t_stack *rotate_stack(t_stack *head)
{
    t_stack *tmp;
    t_stack *tmp2;
    t_stack *A;

    tmp = head;
    tmp2 = (t_stack *)malloc(sizeof(t_stack));
    tmp2->number = tmp->number;
    tmp2->next = NULL;
    head = head->next;
    A = add_back1(&head, tmp2);
    return (head);
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
    t_stack *A;

    A = head;
    while (head->next)
        head = head->next;
    head = head->previous;
    head->next = NULL;
    head = A;
    return (head);
}

t_stack *reverse_stack(t_stack *head)
{
    t_stack *tmp;
    t_stack *new_node;
    t_stack *A;

    A = (t_stack *)malloc(sizeof(t_stack));
    tmp = rr_part1(head);
    A = rr_part2(head);
    head = A;
    new_node = (t_stack *)malloc(sizeof(t_stack));
    new_node->number = tmp->number;
    new_node->next = A;
    new_node->previous = NULL;

    head->previous = new_node;

    head = new_node;
    return (head);
}

void push_stack(t_stack **A, t_stack **B)
{
    t_stack *new;
    t_stack *tmp;

    if (*B == NULL)
    {
        *B = (t_stack *)malloc(sizeof(t_stack ));
        (*B)->previous = NULL;
        (*B)->number = (*A)->number;
        (*B)->next = NULL;
        (*A) = (*A)->next;
        (*A)->previous = NULL;
    }
    else
    {
        new = malloc(sizeof(t_stack));
        new->number = (*A)->number;
        new->next = NULL;
        new->previous = NULL;
        (*A) = (*A)->next;
        (*A)->previous = NULL;
        tmp = (*B);
        while ((*B)->previous != NULL)
            (*B) = (*B)->previous;
        (*B) = new;
        new->next = (tmp);
        new->previous = NULL;
    }
}
