/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:37:50 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/13 08:59:29 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void sort_a_3(t_stack **a, t_stack **b, int len);
void sort_min(t_stack **a, t_stack **b, int len);

t_all *initial(int ac, char **av, t_all *all)
{
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
    if (!(all = (t_all *)malloc(sizeof(t_all))))
        exit(1);
    all->a = NULL;
    all->b = NULL;
    all->len = 0;
    all->line = NULL;
    return (all);
}

int main(int ac, char **av)
{
    t_all *all;

    all = initial(ac, av, all);
    all->a = put_in_list(av);
    all->len = size_list(all->a);
    if (all->len <= 10)
        sort_min(&(all->a), &(all->b), all->len);
    else if (all->len > 10 && all->len < 200)
        algo_1(&(all->a), &(all->b), all->len);
    else
        algo(&(all->a), &(all->b), all->len);
    // print_list(a);
}