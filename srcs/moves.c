/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:59:39 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/03 13:33:28 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *swap_stack(t_stack *head)
{
    int k;
    t_stack *swap;

    swap = head->next;

    k = head->number;
    
    head->number = swap->number;
    
    swap->number  = k;

    return(head);   
}


t_stack *rotate_stack(t_stack *head)
{
    t_stack *tmp;
    t_stack *tmp2;
    t_stack *A;

    tmp = head;
    tmp2 =(t_stack *)malloc(sizeof(t_stack));
    tmp2->number = tmp->number;
    tmp2->next = NULL;
    head = head->next;
    A = add_back1(&head, tmp2);
    return (head);
}