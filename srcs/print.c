/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:06:51 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/08 11:02:11 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_stack *ptr)
{
    t_stack *tmp;
    tmp = ptr;
    while (ptr)
    {
        ft_putstr_fd("[", 1);
        ft_putnbr_fd(ptr->number, 1);
        ft_putstr_fd("]->", 1);
        ptr = ptr->next;
    }
    ft_putstr_fd("\n", 1);
    ptr = tmp;
    return;
}

void print_all(t_stack *A, t_stack *B)
{
    if (A)
    {
        ft_putstr_fd("A:", 1);
        print_list(A);
    }
    else if (A == NULL)
        ft_putstr_fd("A is empty \n", 1);
    if (B)
    {
        ft_putstr_fd("B:", 1);
        print_list(B);
    }
    else if (B == NULL)
        ft_putstr_fd("B is  empty \n", 1);
}