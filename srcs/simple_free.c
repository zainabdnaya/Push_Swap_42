/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:45:17 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/14 16:07:58 by zdnaya           ###   ########.fr       */
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

void free_stack(t_stack **stack)
{
    t_stack *tmp;

    if (*stack)
    {
        while (*stack)
        {
            tmp = (*stack)->next;
            free(*stack);
            (*stack) = tmp;
        }
        free(*stack);
        *stack = NULL;
    }
}

void the_end(t_stack **a, t_stack **b, char **line, t_all *all)
{
    free_stack(a);
    free_stack(b);
    free_arg(line);
    free(all);
    all = NULL;
    exit(0);
}