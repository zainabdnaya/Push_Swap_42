/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:15:44 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/15 15:10:05 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void checker_pars(t_stack **a, t_stack **b, int len, char *line)
{
    if (!ft_strcmp(line, "sa") && size_list(*a) > 1)
        swap_stack(a);
    else if (!ft_strcmp(line, "ra") && size_list(*a) > 1)
        r_stack(a);
    else if (!ft_strcmp(line, "rra") && size_list(*a) > 1)
        rr_stack(a);
    else if (!ft_strcmp(line, "sb") && size_list(*b) > 1)
        swap_stack(b);
    else if (!ft_strcmp(line, "rb") && size_list(*b) > 1)
        r_stack(b);
    else if (!ft_strcmp(line, "rrb") && size_list(*b) > 1)
        rr_stack(b);
    else if (!ft_strcmp(line, "pb") && size_list(*a) >= 1)
        push_stack(a, b);
    else if (!ft_strcmp(line, "pa") && size_list(*b) >= 1)
        push_stack(b, a);
    else if (!ft_strcmp(line, "ss") && size_list(*b) > 1 && size_list(*a) > 1)
        ss(a, b);
    else if (!ft_strcmp(line, "rr") && size_list(*b) > 1 && size_list(*a) > 1)
        rr(a, b);
    else if (!ft_strcmp(line, "rrr") && size_list(*b) > 1 && size_list(*a) > 1)
        rrr(a, b);
    else if (line[0] != '\0' || line[0] != '\n')
    {
        ft_putstr_fd("Error\n", 1);
        exit(1);
    }
}