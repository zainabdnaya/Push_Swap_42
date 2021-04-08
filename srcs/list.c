/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:07:59 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/08 23:44:46 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *add_back(t_stack **head, t_stack *new, char *av)
{
    t_stack *tmp;

    new = (t_stack *)malloc(sizeof(t_stack));
    new->number = my_atoi(av);
    if (new->number > 32767 || new->number < -32768)
    {
        ft_putstr_fd("Error:\n", 2);
        exit(1);
    }
    new->next = NULL;
    new->previous = NULL;
    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        tmp = *head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->previous = tmp;
    }
    return (*head);
}

void add_back1(t_stack **head, t_stack *new)
{
    t_stack *tmp;

    if (!head)
        *head = new;
    else
    {
        tmp = *head;

        if (new)
        {
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = new;
            new->previous = tmp;
        }
    }
}

t_stack *add_front(t_stack **head, t_stack *new_node)
{
    new_node->next = (*head);
    new_node->previous = NULL;

    if ((*head) != NULL)
        (*head)->previous = new_node;
    (*head) = new_node;
    return (*head);
}

t_stack *put_in_list(char **av)
{
    t_stack *a;
    t_stack *tmp;
    char *str;
    int i;

    i = 1;
    a = (t_stack *)malloc(sizeof(t_stack));
    a = NULL;
    tmp = NULL;
    str = NULL;
    while (av[i])
    {
        str = ft_strdup(av[i]);
        add_back(&a, tmp, str);
        // free_stack(tmp);
        // free_arg(&str);
        i++;
    }
    return (a);
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
    exit(1);
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
