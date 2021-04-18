/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:34:16 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/18 16:16:10 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *put_in_list(t_all *all, char **split, t_stack *new)
{
    t_stack *tmp;
    int i;

    i = 0;
    while (split[i])
    {
        if (!(new = malloc(sizeof(t_stack))))
            return (NULL);
        new->number = my_atoi(split[i]);
        if (new->number > 2147483647 || new->number < -2147483647)
        {
            ft_putstr_fd("Error:\n", 2);
            exit(1);
        }
        new->next = NULL;
        new->previous = NULL;
        add_back(&all->a, new, split[i]);
        new = NULL;
        i++;
    }
    return (all->a);
}

int get_pivot(t_stack *c)
{
    t_stack *result;
    int len;
    int m;
    int k;

    t_stack *l;
    k = 0;
    // t_stack *tmp1;
    
    // tmp1 = dup_list(c);
    len = size_list(c);
    result = sort(c);
    if (len <= 12)
        m = val_aprox(len / 2);
    else if (len > 12 && len < 200)
        m = val_aprox(len / 4);
    else if (len >= 200)
        m = val_aprox(len / 8);
    k = node_nbr(&result, m);
    return (k);
}

int get_index(t_stack *a, int pivot)
{
    int i;
    i = 1;

    while (a)
    {
        if (a->number <= pivot)
            return (i);
        a = a->next;
        i++;
    }
    return (-1);
}

int get_index_max(t_stack *a, int pivot)
{
    int i;
    i = 1;

    while (a)
    {
        if (a->number >= pivot)
            return (i);
        a = a->next;
        i++;
    }
    return (-1);
}

int get_max(t_stack *b)
{
    int max;
    t_stack *tmp;

    if (b)
    {
        max = b->number;
        tmp = b;
        while (b)
        {
            if (b->number >= max)
                max = b->number;
            b = b->next;
        }
        b = tmp;
    }
    return (max);
}