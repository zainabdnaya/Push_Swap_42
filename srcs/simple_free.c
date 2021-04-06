/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:45:17 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/06 11:43:53 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_arg(char **arg)
{
    if (*arg)
        free(*arg);
    *arg = NULL;
}
void free_single_stack(t_stack **stack)
{
    free(*stack);
    *stack = NULL;
}
 void free_stack(t_stack *stack)
{
    t_stack *tmp;

    while (stack)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
    free(stack);
    stack = NULL;
}