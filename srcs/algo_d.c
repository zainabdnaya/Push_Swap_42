/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 23:42:09 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/15 23:46:27 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void part_1_d(t_stack **a, t_stack **b, int len, int m)
{
    int index;
    int proximity;
    int size;

    size = len;
    while (size >= val_aprox(len / 8))
    {
        m = get_pivot(((*a)));
        while (check_under_pivot((*a), m) && (*a))
        {
            if ((*a)->number <= m)
            {
                s_c_display(a, b, 1);
                size--;
            }
            else
            {
                index = get_index((*a), m);
                proximity = (size_list((*a)) / 2);
                if (proximity > index)
                    s_c_display(a, b, 2);
                else
                    s_c_display(a, b, 3);
            }
        }
    }
}
void part_2_d(t_stack **a, t_stack **b, int index, int size)
{
    int proximity;
    t_stack *tmp;
    int min;

    while (*a && !check_sort(a, size))
    {
        min = get_min(*a);
        tmp = (*a)->next;
        if ((*a)->number != min && tmp && tmp->number == min)
            s_c_display(a, b, 8);
        while (size_list(*a) && check_under_pivot((*a), min))
        {
            if ((*a)->number == min)
            {
                s_c_display(a, b, 1);
                size--;
            }
            else
            {
                index = get_index((*a), min);
                proximity = (size_list((*a)) / 2);
                if (proximity > index)
                    s_c_display(a, b, 2);
                else
                    s_c_display(a, b, 3);
            }
        }
    }
}

void part_3_d(t_stack **a, t_stack **b, int index, int proximity)
{
    t_stack *tmp;

    while (*b)
    {
        int max = get_max(*b);
        while (check_upper_pivot((*b), max))
        {
            max = get_max(*b);
            tmp = (*b)->next;
            if ((*b)->number != max && tmp && tmp->number == max)
                s_c_display(a, b, 7);
            while (((*b)->number != max) && *b)
            {
                index = get_index_max((*b), max);
                proximity = val_aprox((size_list((*b)) / 2));
                if (proximity > index && *b)
                    s_c_display(a, b, 5);
                else if (*b)
                    s_c_display(a, b, 6);
            }
            while (*b && (*b)->number == max)
            {
                s_c_display(a, b, 4);
                max = get_max(*b);
            }
        }
    }
}

void algo_d(t_stack **a, t_stack **b, int len)
{
    int index;
    int proximity;
    int m;
    int size;

    index = 0;
    proximity = 0;
    m = 0;
    size = len;
    part_1_d(a, b, len, m); 
    part_2_d(a, b, index, size_list(*a));
    part_3_d(a, b, index, proximity); 
}
