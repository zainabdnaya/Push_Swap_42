/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:34:16 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/11 10:14:15 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
        free_stack(&tmp);
        free_arg(&str);
        i++;
    }
    return (a);
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
    else if (len > 12 && len < 500)
        m = val_aprox(len / 5);
    else if (len >= 500)
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
        if (a->number == pivot)
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