/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:59:39 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/06 12:39:00 by zdnaya           ###   ########.fr       */
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

    if (size_list(*head) > 1)
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

    tmp2 = NULL;
    tmp2 = (t_stack *)malloc(sizeof(t_stack));
    tmp2->number = (*head)->number;
    tmp2->next = NULL;
    tmp2->previous = NULL;
    (*head) = (*head)->next;
    add_back1(&(*head), tmp2);
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

void rr_stack(t_stack **head)
{
    t_stack *tmp;
    t_stack *new_node;
    t_stack *A;

    A = (t_stack *)malloc(sizeof(t_stack));
    tmp = rr_part1(*head);
    A = rr_part2(*head);
    *head = A;
    new_node = (t_stack *)malloc(sizeof(t_stack));
    new_node->number = tmp->number;
    new_node->next = A;
    new_node->previous = NULL;

    (*head)->previous = new_node;
    (*head) = new_node;
    free_stack(tmp);
}

void push_stack(t_stack **A, t_stack **B)
{
    t_stack *new;
    t_stack *tmp;

    if (*B == NULL && *A)
    {
        *B = (t_stack *)malloc(sizeof(t_stack));
        (*B)->previous = NULL;
        (*B)->number = (*A)->number;
        (*B)->next = NULL;
        (*A) = (*A)->next;
        (*A)->previous = NULL;
    }
    else
    {
        if (*A)
        {
            new = malloc(sizeof(t_stack));
            new->number = (*A)->number;
            new->next = NULL;
            new->previous = NULL;
            (*A) = (*A)->next;
            // (*A)->previous = NULL;
            // puts("\n ======================>here\n");
            tmp = (*B);
            while ((*B)->previous != NULL)
                (*B) = (*B)->previous;
            (*B) = new;
            new->next = (tmp);
            new->previous = NULL;
        }
        else
            return;
    }
}

void rr(t_stack **A, t_stack **B)
{
    r_stack(A);
    r_stack(B);
}

void ss(t_stack **A, t_stack **B)
{
    swap_stack(A);
    swap_stack(B);
}

void rrr(t_stack **A, t_stack **B)
{
    // puts("here");
    rr_stack(A);
    rr_stack(B);
}