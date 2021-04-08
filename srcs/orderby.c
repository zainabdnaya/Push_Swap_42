/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderby.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:47:46 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/08 23:08:57 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int avreage(t_stack *a)
{
    int k;
    int i;
    int avg;
    t_stack *tmp;

    i = 0;
    k = 0;
    avg = 0;
    tmp = a;
    while (a != NULL)
    {
        k += a->number;
        i++;
        a = a->next;
    }
    a = tmp;
    avg = (int)(k / i);
    return (avg);
}
