/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:59:39 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/03 13:33:28 by zdnaya           ###   ########.fr       */
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

void push_stack(t_stack *push_out, t_stack *push_in)
{
    int i;

    i = 0;
    if (push_in == NULL)
    {
        push_in = (t_stack *)malloc(sizeof(t_stack));
        push_in->next = NULL;
        push_in->previous = NULL;
    }
        push_in->number = push_out->number;
    push_in->next = NULL;
    push_out = push_out->next;
    push_out->previous = NULL;
    printf("\n[push_out]\n");
    print_list(push_out);
    printf("\n[push_in]\n");
    print_list(push_in);
}
