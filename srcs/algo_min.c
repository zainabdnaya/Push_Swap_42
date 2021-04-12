/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:08:38 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/12 16:41:03 by zdnaya           ###   ########.fr       */
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

void sort_a_3(t_stack **a, t_stack **b, int len)
{
    t_stack *bottom1;
    int min;

    bottom1 = NULL;
    min = get_min(*a);
    bottom1 = bottom(*a);
    while (check_sort(a, len) == 0)
    {
        if ((*a)->number < (*a)->next->number && bottom1->number == min)
            switch_case(a, b, 3);
        else if ((*a)->number > (*a)->next->number && bottom1->number == min)
        {
            switch_case(a, b, 8);
            switch_case(a, b, 3);
        }
        else if ((*a)->next->number == min)
        {
            if ((*a)->number > (*a)->next->number && (*a)->number < bottom1->number)
                switch_case(a, b, 8);
            else if ((*a)->number > bottom1->number)
                switch_case(a, b, 2);
        }
        else if ((*a)->number == min && (*a)->next->number > bottom1->number)
        {
            switch_case(a, b, 8);
            switch_case(a, b, 2);
        }
    }
}

// void sort_min(t_stack **a, t_stack **b, int len)
// {
//     t_stack *tmp;
//     int size;
//     int pivot;

//     size = len
//         pivot = get_pivot(a);
//     while (len < val_aprox(len / 2))
//     {
//         if (check_under_pivot(a, pivot))
//         {
//                 }
//     }
// }