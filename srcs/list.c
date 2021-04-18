/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:07:59 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/17 04:47:34 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_back(t_stack **head, t_stack *new, char *av)
{
    t_stack *tmp;

    // if (!(new = (t_stack *)malloc(sizeof(t_stack))))
    //     return;
    // new->number = my_atoi(av);
    // if (new->number > 2147483647 || new->number < -2147483647)
    // {
    //     ft_putstr_fd("Error:\n", 2);
    //     exit(1);
    // }
    // new->next = NULL;
    // new->previous = NULL;

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
    // free_stack(&new);
}

void add_back1(t_stack **head, t_stack *new, int k)
{
    t_stack *tmp;
    t_stack *tmps;

    tmp = NULL;

    tmp = *head;
    tmps = (*head)->previous;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = tmps;
    // new->number = k;
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
    // return (head);
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
    tmp = tmp2;
    while (head)
    {
        tmp2->number = head->number;
        if (head->next)
        {
            tmp2->next = malloc(sizeof(t_stack));
            tmp2 = tmp2->next;
        }
        head = head->next;
    }
    tmp2 = tmp;
    return (tmp2);
}
