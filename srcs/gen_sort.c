/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:45:52 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/10 14:37:58 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void switch_case(t_stack **a, t_stack **b, int w)
{
    if (w == 1)
    {
        ft_putstr_fd("pb\n", 1);
        push_stack(a, b);
    }
    else if (w == 2)
    {
        ft_putstr_fd("ra\n", 1);
        r_stack(a);
    }
    else if (w == 3 && size_list(*a) > 1)
    {
        ft_putstr_fd("rra\n", 1);
        rr_stack(a);
    }
    else if (w == 4)
    {
        ft_putstr_fd("pa\n", 1);
        push_stack(b, a);
    }
    else if (w == 5 && size_list(*b) > 1)
    {
        ft_putstr_fd("rb\n", 1);
        r_stack(b);
    }
    else if (w == 6 && size_list(*b) > 1)
    {
        ft_putstr_fd("rrb\n", 1);
        rr_stack(b);
    }
}

void swap(t_stack *one, t_stack *two)
{
    int k;

    k = one->number;
    one->number = two->number;
    two->number = k;
}

t_stack *sort(t_stack *head)
{
    t_stack *start;
    t_stack *tmp2;
    t_stack *min;

    start = head;
    while (start->next)
    {
        min = start;
        tmp2 = start->next;
        while (tmp2)
        {
            if (min->number > tmp2->number)
                min = tmp2;
            tmp2 = tmp2->next;
        }
        swap(start, min);
        start = start->next;
    }
    return (head);
}