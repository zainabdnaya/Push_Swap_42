/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:08:35 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/17 04:50:15 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void switch_case_color(t_stack **a, t_stack **b, int w)
// {

//     if (w == 1 && size_list(*a) > 0)
//     {
//         ft_putendl_fd(WHT, 1);
//         push_stack(a, b);
//     }
//     else if (w == 2)
//     {
//         ft_putendl_fd(GRN, 1);
//         r_stack(a);
//     }
//     else if (w == 3 && size_list(*a) > 1)
//     {
//         ft_putendl_fd(YEL, 1);
//         rr_stack(a,tmp);
//     }
//     else if (w == 4  && size_list(*a) > 0)
//     {
//         ft_putendl_fd(BLU, 1);
//         push_stack(b, a);
//     }
//     else if (w == 5 && size_list(*b) > 1)
//     {
//         ft_putendl_fd(MAG, 1);
//         r_stack(b);
//     }
//     else if (w == 6 && size_list(*b) > 1)
//     {
//         ft_putendl_fd(CYN, 1);
//         rr_stack(b);
//     }
//     else if (w == 7 && size_list(*b) > 1)
//     {
//         ft_putendl_fd(BHBLK, 1);
//         swap_stack(b);
//     }
//     else if (w == 8 && size_list(*a) > 1)
//     {
//         ft_putendl_fd(RED, 1);
//         swap_stack(a);
//     }
// }

// void display(t_stack *a, t_stack *b)
// {
//     int len;

//     len = size_list(a);
//     system("clear");
//     ft_putstr_fd("\n\t-------------------------------\n", 1);
//     ft_putstr_fd("        \tA         \tB         ", 1);
//     ft_putstr_fd("\n\t-------------------------------\n", 1);
//     while ((a) || (b))
//     {
//         ft_putstr_fd("\t        ", 1);
//         if ((a))
//             ft_putnbr_fd((a)->number, 1);
//         else
//             ft_putstr_fd("   ", 1);
//         ft_putstr_fd("\t        ", 1);
//         if (b)
//             ft_putnbr_fd((b)->number, 1);
//         else
//             ft_putstr_fd("   ", 1);
//         ft_putstr_fd("\n", 1);
//         if (a)
//             (a) = (a)->next;
//         if (b)
//             b = (b)->next;
//     }
//     if ( len <= 10)
//     usleep(100000);
//     else if(len > 10 && len <= 100)
//         usleep(1000000);
//     else  if ( len > 100)
//         usleep(100000);
// }

// void s_c_display(t_stack **a, t_stack **b, int w)
// {
//     if (w == 1 && size_list(*a) > 0)
//         push_stack(a, b);
//     else if (w == 2 && size_list(*a) > 1)
//         r_stack(a);
//     else if (w == 3 && size_list(*a) > 1)
//         rr_stack(a);
//     else if (w == 4 && size_list(*b) > 0)
//         push_stack(b, a);
//     else if (w == 5 && size_list(*b) > 1)
//         r_stack(b);
//     else if (w == 6 && size_list(*b) > 1)
//         rr_stack(b);
//     else if (w == 7 && size_list(*b) > 1)
//         swap_stack(b);
//     else if (w == 8 && size_list(*a) > 1)
//         swap_stack(a);
//     display(*a, *b);
// }

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
    else if (w == 4)
    {
        ft_putstr_fd("pa\n", 1);
        push_stack(b, a, tmp);
        free(tmp);
        tmp = NULL;
    }
    else if (w == 5 && size_list(*b) > 1)
    {
        ft_putstr_fd("rb\n", 1);
        r_stack(b,tmp);
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
