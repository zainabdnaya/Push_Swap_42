/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:28:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/10 14:29:40 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void le_vide_vider(t_stack **a, t_stack **b)
{
    while (*a)
    {
        // switch_case(a, b, 3);
        // sleep(1);
        switch_case(a, b, 1);
    }

    int i;

    i = 0;
    while (*b)
    {
        switch_case(a, b, 4);
        // puts("\n\n");
        // puts("------B befor rrb-----");
        // print_list(*b);
        // puts("----------------------");
        switch_case(a, b, 6);
        // i++;
        // sleep(1);
    }
    // // free(*a);
    // // free_stack(a);
    // // puts(ft_itoa());
    // if (size_list(*b))
    //     switch_case(a, b, 6);
}