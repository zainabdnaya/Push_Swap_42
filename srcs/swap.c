/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:37:50 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/11 12:41:47 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    int len;

    a = NULL;
    b = NULL;
    if (ac < 2)
    {
        ft_putstr_fd("Error:\n", 0);
        exit(1);
    }
    if (ac == 2)
    {
        write(1, av[1], 1);
        exit(1);
    }
    else
    {
        a = put_in_list(av);
        len = size_list(a);
        if (len < 200)
            algo_1(&a, &b, len);
        else
            algo(&a, &b, len);
    }
}