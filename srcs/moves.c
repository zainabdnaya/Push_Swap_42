/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:59:39 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/03 12:41:17 by zdnaya           ###   ########.fr       */
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
    

    return(head);
}