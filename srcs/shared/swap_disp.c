/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_disp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:27:40 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/20 16:33:46 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void switch_norm(t_stack **a, t_stack **b, int w, t_stack *tmp)
{
    if (w == 4 && size_list(*b) > 0)
    {
        ft_putendl_fd(BLU, 1);
        push_stack(b, a, tmp);
        free(tmp);
        tmp = NULL;
    }
    else if (w == 5 && size_list(*b) > 1)
    {
        ft_putendl_fd(MAG, 1);
        r_stack(b);
        free(tmp);
        tmp = NULL;
    }
    else if (w == 6 && size_list(*b) > 1)
    {
        ft_putendl_fd(CYN, 1);
        rr_stack(b, tmp);
        free(tmp);
        tmp = NULL;
    }
    else if (w == 7 && size_list(*b) > 1)
    {
        ft_putendl_fd(BHBLK, 1);
        swap_stack(b);
    }
}
void switch_case_color(t_stack **a, t_stack **b, int w)
{
    t_stack *tmp;

    tmp = NULL;
    if (w == 1 && size_list(*a) > 0)
    {
        ft_putendl_fd(WHT, 1);
        push_stack(a, b, tmp);
    }
    else if (w == 2)
    {
        ft_putendl_fd(GRN, 1);
        r_stack(a);
    }
    else if (w == 3 && size_list(*a) > 1)
    {
        ft_putendl_fd(YEL, 1);
        rr_stack(a, tmp);
    }
    else if (w == 8 && size_list(*a) > 1)
    {
        ft_putendl_fd(RED, 1);
        swap_stack(a);
    }
    else
        switch_norm(a, b, w, tmp);
    free_stack(&tmp);
}

void s_c_display(t_stack **a, t_stack **b, int w)
{
    t_stack *tmp;

    tmp = NULL;
    if (w == 1)
        push_stack(a, b, tmp);
    else if (w == 2 && size_list(*a) > 1)
        r_stack(a);
    else if (w == 3 && size_list(*a) > 1)
        rr_stack(a, tmp);
    else if (w == 4)
        push_stack(b, a, tmp);
    else if (w == 5 && size_list(*b) > 1)
        r_stack(b);
    else if (w == 6 && size_list(*b) > 1)
        rr_stack(b, tmp);
    else if (w == 7 && size_list(*b) > 1)
    {
        ft_putstr_fd("sb\n", 1);
        swap_stack(b);
    }
    else if (w == 8 && size_list(*a) > 1)
        swap_stack(a);
    free_stack(&tmp);
    display(*a, *b);
}
