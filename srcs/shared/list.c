/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:07:59 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/20 16:08:11 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_back(t_stack **head, t_stack *new)
{
    t_stack *tmp;

    if (*head == NULL)
        *head = new;
    else
    {
        tmp = *head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->previous = tmp;
    }
}

void add_back1(t_stack **head)
{
    t_stack *tmp;
    t_stack *tmps;

    tmp = NULL;

    tmp = *head;
    tmps = (*head)->previous;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = tmps;
    tmp->next->previous = tmp;
    tmp->next->next = NULL;
}

void add_front(t_stack **head, t_stack *new_node)
{
    new_node->next = (*head);
    new_node->previous = NULL;

    if ((*head) != NULL)
        (*head)->previous = new_node;
    (*head) = new_node;
}

int node_nbr(t_stack **head, int index)
{

    t_stack *tmp;
    int count;

    count = 0;
    tmp = *head;
    while (tmp != NULL)
    {
        if (count == index)
            return (tmp->number);
        count++;
        tmp = tmp->next;
    }
    return (1);
}

t_stack *dup_list(t_stack *head)
{
    t_stack *tmp;
    t_stack *tmp2;

    tmp2 = malloc(sizeof(t_stack));
    ft_bzero(tmp2,sizeof(t_stack));
    tmp = tmp2;
    while (head)
    {
        tmp2->number = head->number;
        if (head->next)
        {
            tmp2->next = malloc(sizeof(t_stack));
            ft_bzero(tmp2->next,sizeof(t_stack));
            tmp2 = tmp2->next;
        }
        head = head->next;
    }
    tmp2 = tmp;
    return (tmp2);
}
