/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:06:51 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/07 17:26:25 by zdnaya           ###   ########.fr       */
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
    puts("\n");
    ptr = tmp;
    return;
}