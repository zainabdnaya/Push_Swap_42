/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:08:35 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/17 16:55:47 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void switch_case_norm(t_stack **a, t_stack **b, int w, t_stack *tmp)
{
    if (w == 4)
    {
        ft_putstr_fd("pa\n", 1);
        push_stack(b, a, tmp);
        free(tmp);
        tmp = NULL;
    }
    else if (w == 5 && size_list(*b) > 1)
    {
        ft_putstr_fd("rb\n", 1);
        r_stack(b, tmp);
        free(tmp);
        tmp = NULL;
    }
    else if (w == 6 && size_list(*b) > 1)
    {
        ft_putstr_fd("rrb\n", 1);
        rr_stack(b, tmp);
        free(tmp);
        tmp = NULL;
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

void switch_case(t_stack **a, t_stack **b, int w)
{
    t_stack *tmp;

    tmp = NULL;
    if (w == 1)
    {
        ft_putstr_fd("pb\n", 1);
        push_stack(a, b, tmp);
        free(tmp);
        tmp = NULL;
    }
    else if (w == 2)
    {
        ft_putstr_fd("ra\n", 1);
        r_stack(a,tmp);
        free(tmp);
        tmp = NULL;
    }
    else if (w == 3 && size_list(*a) > 1)
    {
        ft_putstr_fd("rra\n", 1);
        rr_stack(a, tmp);
        free(tmp);
        tmp = NULL;
    }
    else
        switch_case_norm(a, b, w, tmp);
}
