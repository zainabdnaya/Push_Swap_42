/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:08:35 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/14 12:00:22 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void switch_case(t_stack **a, t_stack **b, int w)
{
    if (w == 1 && size_list(*a) > 0)
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
    else if (w == 7 && size_list(*b) > 1)
    {
        ft_putstr_fd("sb\n", 1);
        swap_stack(b);
    }
    else if (w == 8 && size_list(*a) > 1)
    {
        ft_putstr_fd("sa\n", 1);
        swap_stack(a);
    }
}
