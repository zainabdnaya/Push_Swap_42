/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:34:16 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/13 23:32:04 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *put_in_list(t_all *all,char **split)
{
    t_stack *tmp;
    // char *str;
    int i;

    i = 0;
    tmp = NULL;
    // str = NULL;
    all->a = (t_stack *)malloc(sizeof(t_stack));
    all->a = NULL;
    while (split[i])
    {
        add_back(&all->a, tmp, split[i]);
        free_stack(&tmp);
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

    result = sort(dup_list(c));
    len = size_list(result);
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