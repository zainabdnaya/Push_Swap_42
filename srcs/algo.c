/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:06:00 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/10 14:51:07 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo(t_stack **a, t_stack **b, int len)
{
    t_stack *now;
    int index;
    int proximity;
    int m;
    int size = len;

    now = (*a);
    while (size >= len / 5)
    {
        m = get_pivot(((*a)));
        while (check_under_pivot((*a), m))
        {
            if ((*a)->number <= m)
            {
                switch_case(a, b, 1);
                size--;
            }
            else
            {
                index = get_index((*a), m);
                proximity = (size_list((*a)) / 2);
                if (proximity > index)
                    switch_case(a, b, 2);
                else
                    switch_case(a, b, 3);
            }
        }
    }
    size = size_list(*a);
    while (*a && !check_sort(a, size))
    {
        int min = get_min(*a);
        while (size_list(*a) && check_under_pivot((*a), min))
        {
            if ((*a)->number == min)
            {
                switch_case(a, b, 1);
                size--;
            }
            else
            {
                index = get_index((*a), min);
                proximity = (size_list((*a)) / 2);
                if (proximity > index)
                    switch_case(a, b, 2);
                else
                    switch_case(a, b, 3);
            }
        }
    }
    while (*b)
    {
        int max = get_max(*b);
        while (check_upper_pivot((*b), max))
        {
            max = get_max(*b);
            while (((*b)->number != max))
            {
                index = get_index_max((*b), max);
                proximity = val_aprox((size_list((*b)) / 2));
                if (proximity > index && *b) //|| size < 30
                    switch_case(a, b, 5);
                else if (*b)

                    switch_case(a, b, 6);
            }
            while (*b && (*b)->number == max)
            {
                switch_case(a, b, 4);
                max = get_max(*b);
            }
        }
    }
}
