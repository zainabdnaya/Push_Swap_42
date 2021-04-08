/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:37:50 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/08 18:18:10 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    int m;

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
        t_stack *c;

        a = put_in_list(av);
        c = put_in_list(av);
        // print_list(a);
        m = get_pivot(c);
        // printf("pivot==>%d\n", m );
        algo(&a, &b, m);
        print_all(a, b);
    }
}