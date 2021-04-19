/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:08:38 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/19 23:47:28 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *bottom(t_stack *a)
{
    t_stack *bottom;

    bottom = a;
    while ((bottom)->next)
        (bottom) = (bottom)->next;
    return (bottom);
}

void sort_a_3(t_stack **a, t_stack **b, int len, int k)
{
    t_stack *bottom1;
    int min;

    bottom1 = NULL;
    min = get_min(*a);
    bottom1 = bottom(*a);
    while (check_sort(a, len) == 0)
    {
        if ((*a)->number < (*a)->next->number && bottom1->number == min)
            switch_case(a, b, 3,k);
        else if ((*a)->number > (*a)->next->number && bottom1->number == min)
        {
            switch_case(a, b, 8,k);
            switch_case(a, b, 3,k);
        }
        else if ((*a)->next->number == min)
        {
            if ((*a)->number > (*a)->next->number && (*a)->number < bottom1->number)
                switch_case(a, b, 8,k);
            else if ((*a)->number > bottom1->number)
                switch_case(a, b, 2,k);
        }
        else if ((*a)->number == min && (*a)->next->number > bottom1->number)
        {
            switch_case(a, b, 8,k);
            switch_case(a, b, 2,k);
        }
    }
}

void sort_min(t_stack **a, t_stack **b, int len, int k)
{
    t_stack *tmp;
    int index;
    int proximity;
    int size;
    int m;
    int min;
    int max;

    size = len;
    if (len == 3)
        sort_a_3(a, b, len, k);
    else if (len > 3)
    {
        while (size > 3)
        {
            m = get_min(*a);
            tmp = (*a)->next;
            if ((*a)->number != max && tmp && tmp->number == min)
                switch_case(a, b, 8, k);
            while (m != (*a)->number)
            {
                proximity = size_list(*a) / 2;
                index = get_index(*a, m);
                if (proximity >= index)
                    switch_case(a, b, 2, k);
                else
                    switch_case(a, b, 3, k);
            }
            if (m == (*a)->number)
            {
                t_stack *ss = *a;
                switch_case(a, b, 1, k);
                free(ss);
                size--;
            }
        }
        sort_a_3(a, b, 3, k);
        while ((*b))
        {
            t_stack *ss = *b;
            switch_case(a, b, 4, k);
            free(ss);
        }
        free_stack(b);
    }
    free_stack(a);
}