/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:15:44 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/20 16:08:13 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void checker_pars_v(t_stack **a, t_stack **b, char *line)
{
     t_stack *tmp;

    tmp = NULL;
    if (!ft_strcmp(line, "sa\n") && size_list(*a) > 1)
        swap_stack(a);
    else if (!ft_strcmp(line, "ra\n") && size_list(*a) > 1)
        r_stack(a);
    else if (!ft_strcmp(line, "rra\n") && size_list(*a) > 1)
        rr_stack(a,tmp);
    else if (!ft_strcmp(line, "sb\n") && size_list(*b) > 1)
        swap_stack(b);
    else if (!ft_strcmp(line, "rb\n") && size_list(*b) > 1)
        r_stack(b);
    else if (!ft_strcmp(line, "rrb\n") && size_list(*b) > 1)
        rr_stack(b,tmp);
    else if (!ft_strcmp(line, "pb\n"))
        push_stack(a, b,tmp);
    else if (!ft_strcmp(line, "pa\n"))
        push_stack(b, a,tmp);
    else if (!ft_strcmp(line, "ss\n") && size_list(*b) > 1 && size_list(*a) > 1)
        ss(a, b);
    else if (!ft_strcmp(line, "rr\n") && size_list(*b) > 1 && size_list(*a) > 1)
        rr(a, b);
    else if (!ft_strcmp(line, "rrr\n") && size_list(*b) > 1 && size_list(*a) > 1)
        rrr(a, b);
}

void checker_pars(t_stack **a, t_stack **b,  char *line)
{
    t_stack *tmp;

    tmp = NULL;
    if (!ft_strcmp(line, "sa") && size_list(*a) > 1)
        swap_stack(a);
    else if (!ft_strcmp(line, "ra") && size_list(*a) > 1)
        r_stack(a);
    else if (!ft_strcmp(line, "rra") && size_list(*a) > 1)
        rr_stack(a,tmp);
    else if (!ft_strcmp(line, "sb") && size_list(*b) > 1)
        swap_stack(b);
    else if (!ft_strcmp(line, "rb") && size_list(*b) > 1)
        r_stack(b);
    else if (!ft_strcmp(line, "rrb") && size_list(*b) > 1)
        rr_stack(b,tmp);
    else if (!ft_strcmp(line, "pb"))
        push_stack(a, b,tmp);
    else if (!ft_strcmp(line, "pa"))
        push_stack(b, a,tmp);
    else if (!ft_strcmp(line, "ss") && size_list(*b) > 1 && size_list(*a) > 1)
        ss(a, b);
    else if (!ft_strcmp(line, "rr") && size_list(*b) > 1 && size_list(*a) > 1)
        rr(a, b);
    else if (!ft_strcmp(line, "rrr") && size_list(*b) > 1 && size_list(*a) > 1)
        rrr(a, b);
    free_stack(&tmp);
}

