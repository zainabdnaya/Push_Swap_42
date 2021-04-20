/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:01:02 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/20 17:10:29 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void part1_1_c(t_stack **a, t_stack **b, int len)
{
    int size;
    int m;
    t_stack *tmp;
    t_stack *tmps;

    size = len;
    while (size >= val_aprox(len / 4))
    {
        tmps = dup_list(*a);
        m = get_pivot(tmps);
        while (check_under_pivot((*a), m) && (*a))
        {
            if ((*a)->number <= m)
            {
                tmp = *a;
                switch_case_color(a, b, 1);
                size--;
                free(tmp);
            }
            else
                norm_part1_c(a, b, m,1);
        }
        free_stack(&tmps);
    }
}

void part1_2_c(t_stack **a, t_stack **b, int size)
{
    int min;
    t_stack *tmp;

    tmp = NULL;
    while (*a && !check_sort(a, size))
    {
        min = get_min(*a);
        tmp = (*a)->next;
        while ((*a)->number != min && tmp && tmp->number == min)
            switch_case_color(a, b, 8);
        while (size_list(*a) && check_under_pivot((*a), min))
        {
            if ((*a)->number == min)
            {
                tmp = *a;
                switch_case_color(a, b, 1);
                free(tmp);
                size--;
            }
            else
                norm_part1_c(a, b,  min,1);
        }
    }
}

void part1_3_c(t_stack **a, t_stack **b, int max)
{
    t_stack *tmp;

    tmp = NULL;
    while (*b)
    {
        max = get_max(*b);
        while (check_upper_pivot((*b), max))
        {
            max = get_max(*b);
            tmp = (*b)->next;
            while ((*b)->number != max && tmp && tmp->number == max)
                switch_case_color(a, b, 7);
            while (((*b)->number != max) && *b)
                norm_part3_c(a, b, max,1);
            while (*b && (*b)->number == max)
            {
                tmp = *b;
                switch_case_color(a, b, 4);
                max = get_max(*b);
                free(tmp);
            }
        }
    }
}

void algo_1_c(t_stack **a, t_stack **b, int len)
{
    int m;

    m = 0;
    part1_3_c(a, b, len);
    part1_2_c(a, b, len);
    part1_3_c(a, b, m);
    free_stack(a);
    free_stack(b);
}
