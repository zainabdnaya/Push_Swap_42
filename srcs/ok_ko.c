/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_ko.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:45:25 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/08 12:08:11 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_stack **A, int len)
{
    t_stack *tmp;
    int i;

    i = 0;
    if (size_list(*A) != len)
        return (0);
    tmp = (*A);
    while (tmp && tmp->next)
    {
        if ((tmp)->next != NULL && ((tmp)->number < (tmp)->next->number))
            (tmp) = (tmp)->next;
        else
            return (0);
    }
    (*A) = tmp;
    return (1);
}
