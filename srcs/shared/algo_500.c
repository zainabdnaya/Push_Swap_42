
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:38:17 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/18 23:47:41 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void part_1(t_stack **a, t_stack **b, int len, t_all *all)
{
    int index;
    int proximity;
    int size;
    int m;
    t_stack *tmp;
    t_stack *tmps;

    size = len;
    while (size >= val_aprox(len / 8))
    {
        tmps = dup_list(*a);
        m = get_pivot(tmps);
        while (check_under_pivot((*a), m) && (*a))
        {
            if ((*a)->number <= m)
            {
                tmp = *a;
                switch_case(a, b, 1,all);
                size--;
                free(tmp);
            }
            else
            {
                index = get_index((*a), m);
                proximity = (size_list((*a)) / 2);
                if (proximity > index)
                    switch_case(a, b, 2,all);
                else
                    switch_case(a, b, 3,all);
            }
        }
        // free(tmps);
        free_stack(&tmps);
    }
}
void part_2(t_stack **a, t_stack **b, t_all *all, int size)
{
    int proximity;
    t_stack *tmp;
    t_stack *tmps;
    int min;
     int index;

    while (*a && !check_sort(a, size))
    {
        min = get_min(*a);
        tmp = (*a)->next;
        while ((*a)->number != min && tmp && tmp->number == min)
            switch_case(a, b, 8,all);
        while (size_list(*a) && check_under_pivot((*a), min))
        {
            if ((*a)->number == min)
            {
                tmps = *a;
                switch_case(a, b, 1,all);
                free(tmps);
                size--;
            }
            else
            {
                index = get_index((*a), min);
                proximity = (size_list((*a)) / 2);
                if (proximity > index)
                    switch_case(a, b, 2,all);
                else
                    switch_case(a, b, 3,all);
            }
        }
    }
}

void part_3(t_stack **a, t_stack **b, t_all *all, int proximity)
{
    t_stack *tmp;
    t_stack *tmps;
    int index;
    while (*b)
    {
        int max = get_max(*b);
        while (check_upper_pivot((*b), max))
        {
            max = get_max(*b);
            tmp = (*b)->next;
            while ((*b)->number != max && tmp && tmp->number == max)
                switch_case(a, b, 7,all);
            while (((*b)->number != max) && *b)
            {
                index = get_index_max((*b), max);
                proximity = val_aprox((size_list((*b)) / 2));
                if (proximity > index && *b)
                    switch_case(a, b, 5,all);
                else if (*b)
                    switch_case(a, b, 6,all);
            }
            while (*b && (*b)->number == max)
            {
                tmps = *b;
                switch_case(a, b, 4,all);
                max = get_max(*b);
                free(tmps);
            }
        }
    }
}

void algo(t_stack **a, t_stack **b, int len,t_all *all)
{
    int index;
    int proximity;
    int m;
    int size;

    index = 0;
    proximity = 0;
    m = 0;
    size = len;
    part_1(a, b, len, all);
    part_2(a, b, all, size_list(*a));
    part_3(a, b, all, proximity);
    free_stack(a);
    free_stack(b);
}
