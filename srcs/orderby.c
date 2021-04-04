/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderby.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:47:46 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/04 16:31:49 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    avreage(t_stack *A)
{
    int k;
    int i;
    int avg;
    t_stack *tmp;

    i = 0;
    k = 0;
    avg = 0;
    tmp = A;
    while (A != NULL)
    {
        k += A->number;
        i++;
        A = A->next;
    }
    A = tmp;
    avg = (int)(k / i);
    return (avg);
}

