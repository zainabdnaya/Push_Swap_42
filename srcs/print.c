/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:06:51 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/09 17:22:24 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_stack *ptr)
{
    t_stack *tmp;
    tmp = ptr;
    while (ptr)
    {
        // ft_putstr_fd("k:", 1);
        // ft_putnbr_fd(ptr->index, 1);
        ft_putstr_fd("[", 1);
        ft_putnbr_fd(ptr->number, 1);
        ft_putstr_fd("]-->", 1);

        ptr = ptr->next;
    }
    ft_putstr_fd("\n", 1);
    ptr = tmp;
    return;
}

void print_all(t_stack *a, t_stack *b)
{
    if (a)
    {
        ft_putstr_fd("a:", 1);
        print_list(a);
    }
    else if (a == NULL)
        ft_putstr_fd("a is empty \n", 1);
    if (b)
    {
        ft_putstr_fd("b:", 1);
        print_list(b);
    }
    else if (b== NULL)
        ft_putstr_fd("b is empty \n", 1);
}