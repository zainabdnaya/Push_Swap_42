/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:08:35 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/19 23:28:48 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void switch_case_norm(t_stack **a, t_stack **b, int w, int fd)
{
    t_stack *tmp;

    tmp = NULL;
    if (w == 4)
    {
        ft_putstr_fd("pa\n", fd);
        push_stack(b, a, tmp);
        free(tmp);
        tmp = NULL;
    }
    else if (w == 5 && size_list(*b) > 1)
    {
        ft_putstr_fd("rb\n", fd);
        r_stack(b, tmp);
        free(tmp);
        tmp = NULL;
    }
    else if (w == 6 && size_list(*b) > 1)
    {
        ft_putstr_fd("rrb\n", fd);
        rr_stack(b, tmp);
        free(tmp);
        tmp = NULL;
    }
    else if (w == 7 && size_list(*b) > 1)
    {
        ft_putstr_fd("sb\n", fd);
        swap_stack(b);
    }
    else if (w == 8 && size_list(*a) > 1)
    {
        ft_putstr_fd("sa\n", fd);
        swap_stack(a);
    }
}

void switch_case(t_stack **a, t_stack **b, int w, int k)
{
    t_stack *tmp;
    int  fd;
    
    tmp = NULL;
    fd = 1;
    if (k == 1)
    {
        fd = open("swap.log", O_CREAT | O_RDWR ,0666);
            if (fd == -1)
            ft_putstr_fd("Error! opening file",1);
     }
    if (w == 1)
    {
            ft_putstr_fd("pb\n", fd);
            push_stack(a, b, tmp);
            free(tmp);
            tmp = NULL;
    }
    else if (w == 2)
    {
            ft_putstr_fd("ra\n", fd);
            r_stack(a, tmp);
            free(tmp);
            tmp = NULL;
    }
    else if (w == 3 && size_list(*a) > 1)
    {
            ft_putstr_fd("rra\n", fd);
            rr_stack(a, tmp);
    }
    else
        switch_case_norm(a, b, w, fd);
    }
