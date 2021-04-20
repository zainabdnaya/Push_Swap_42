/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:09:10 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/20 04:04:05 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_a_3_d(t_stack **a, t_stack **b, int len)
{
    t_stack *bottom1;
    int min;

    bottom1 = NULL;
    min = get_min(*a);
    bottom1 = bottom(*a);
    while (check_sort(a, len) == 0)
    {

        if ((*a)->number < (*a)->next->number && bottom1->number == min)
            s_c_display(a, b, 3);
        else if ((*a)->number > (*a)->next->number && bottom1->number == min)
        {
            s_c_display(a, b, 8);
            s_c_display(a, b, 3);
        }
        else if ((*a)->next->number == min)
        {
            if ((*a)->number > (*a)->next->number && (*a)->number < bottom1->number)
                s_c_display(a, b, 8);
            else if ((*a)->number > bottom1->number)
                s_c_display(a, b, 2);
        }
        else if ((*a)->number == min && (*a)->next->number > bottom1->number)
        {
            s_c_display(a, b, 8);
            s_c_display(a, b, 2);
        }
    }
}

void sort_min_d(t_stack **a, t_stack **b, int len)
{
    t_stack *tmp;
    int index;
    int proximity;
    int size;
    int m;
    int min;
    int max;

    size = len;
    min = 0;
    max = 0;
    if (len == 3)
        sort_a_3_d(a, b, len);
    else if (len > 3)
    {
        while (size > 3)
        {
            m = get_min(*a);
            tmp = (*a)->next;
            if ((*a)->number != max && tmp && tmp->number == min)
                s_c_display(a, b, 8);
            while (m != (*a)->number)
            {
                proximity = size_list(*a) / 2;
                index = get_index(*a, m);
                if (proximity >= index)
                    s_c_display(a, b, 2);
                else
                    s_c_display(a, b, 3);
            }
            if (m == (*a)->number)
            {
                t_stack *ss = *a;
                s_c_display(a, b, 1);
                free(ss);
                size--;
            }
        }
        sort_a_3_d(a, b, 3);
        while ((*b))
        {
            t_stack *ss = *b;
            s_c_display(a, b, 4);
            free(ss);
        }
        free_stack(b);
    }
    free_stack(a);
}