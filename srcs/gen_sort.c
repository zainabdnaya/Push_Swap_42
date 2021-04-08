/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:45:52 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/08 16:55:20 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void swap(t_stack *one,t_stack *two)
{
    int k;

    k = one->number;
    one->number = two->number;
    two->number = k;
}
void    sort(t_stack *head)
{
    t_stack *start;
    t_stack *tmp2;
    t_stack *min;
    t_stack *tmp;

    start = head;
    tmp = head;
    while (start->next)
    {
        min = start;
        tmp2 = start->next;
        while(tmp2)
        {
            if( min->number > tmp2->number)
                min = tmp2;
            tmp2 = tmp2->next;
        }
        swap(start, min);
        start = start->next;
    }
    head = tmp;
    // print_list(tmp);
    // exit(1);
}