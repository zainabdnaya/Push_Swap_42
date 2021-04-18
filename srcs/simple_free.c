/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:45:17 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/18 16:42:36 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_arg(char **arg)
{
    if (*arg)
        free(*arg);
    *arg = NULL;
}

void ft_free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		free_arg(&(split[i]));
		i++;
	}
	free(*split);
	*split = NULL;
}

void free_single_stack(t_stack **stack)
{
    free(*stack);
    *stack = NULL;
}

void free_stack(t_stack **stack)
{
    t_stack *tmp;

    tmp = NULL;
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
    /******free****/
    // if (ac == 2 || ac == 3)
    // {
    //     while (all->split[i])
    //     {
    //         free_arg(&all->split[i]);
    //         all->split[i] = NULL;
    //         i++;
    //     }
    //     free_arg(all->split);
    //     all->split = NULL;
    // }
    // print_list(all->a);
    // if (ac == 2)
    // {
    //     while (all->split[i])
    //     {
    //         free_arg(&all->split[i]);
    //         all->split[i] = NULL;
    //         i++;
    //     }
    //     free_arg(all->split);
    //     all->split = NULL;
    // }
}