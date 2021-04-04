/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordnate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:22:55 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/04 17:08:41 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void first(t_stack **A, t_stack **B)
{
    t_stack *tmp;

    int m;

    m = avreage(*A);
    // (void)B;
    while ((*A) != NULL)
    {
        // printf("==>%d\n", (*A)->number);
        // printf("==>%d", (*B)->number);
        while ((*A)->number <= m)
            push_stack(A, B);
        tmp = *A;
        if ((*A )->number > m)
        {
            rotate_stack((A));
            while ((*A)->number <= m)
                push_stack(A, B);
            tmp = *A;
        }
        (*A) = (*A)->next;
    }
    *A = tmp;
}