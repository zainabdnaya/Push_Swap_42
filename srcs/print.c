/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:06:51 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/06 11:13:49 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_stack *ptr)
{
    t_stack *tmp;
    tmp = ptr;
    while (ptr != NULL)
    {
        printf("[%d]->", ptr->number);
        ptr = ptr->next;
    }
    puts("\n");
    ptr = tmp;
    return;
}