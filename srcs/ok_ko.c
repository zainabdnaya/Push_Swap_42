/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_ko.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:45:25 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/06 11:19:48 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_stack **A)
{
    t_stack *tmp;

    tmp = *A;
    while (*A && (*A)->next)
    {
        if ((*A)->number < (*A)->next->number)
            (*A) = (*A)->next;
        else
            return (0);
    }
    *A = tmp;
    return (1);
}
void sort_result(t_stack *A)
{
    if (check_sort(&A) == 1)
    {
        ft_putstr_fd("ok\n", 2);
        exit(0);
    }
    else
        return;
}