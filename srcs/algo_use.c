/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_use.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:07:20 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/12 09:09:27 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_under_pivot(t_stack *a, int pivot)
{
    while (a)
    {
        if (a->number <= pivot)
            return (1);
        a = a->next;
    }
    return (0);
}

int check_upper_pivot(t_stack *a, int pivot)
{
    while (a)
    {
        if (a->number == pivot)
            return (1);
        a = a->next;
    }
    return (0);
}

int get_min(t_stack *a)
{
    int min;
    
    min = a->number;
    t_stack *tmp;
    tmp = a;
    while (a)
    {
        if (a->number < min)
            min = a->number;
        a = a->next;
    }
    return (min);
}