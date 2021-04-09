/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_ko.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:45:25 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/09 14:08:34 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_stack **a, int len)
{
    t_stack *tmp;
    int i;

    i = 0;
    if (size_list(*a) != len)
        return (0);
    tmp = (*a);
    while (tmp && tmp->next)
    {
        if ((tmp)->next != NULL && ((tmp)->number < (tmp)->next->number))
            (tmp) = (tmp)->next;
        else
            return (0);
    }
    (*a) = tmp;
    return (1);
}
