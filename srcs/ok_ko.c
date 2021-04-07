/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_ko.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:45:25 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/07 16:41:32 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_stack *A,int len)
{
    t_stack *tmp;
    int i;

    tmp = A;
    i = 0;
    while ( i < len && tmp)
    {
        if ( (tmp)->next != NULL && ((tmp)->number < (tmp)->next->number))
            {
                (tmp) = (tmp)->next;
                i++;
            }
        else
            return (0);
    }
    A = tmp;
    if ( size_list(A) != len)
        return (0);
    return (1);
}
void sort_result(t_stack *A,int len)
{
    if (check_sort(A,len) == 1)
    {
        ft_putstr_fd("ok\n", 2);
        exit(0);
    }
    else
        return;
}