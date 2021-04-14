/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/14 00:27:24 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void the_end(t_stack **a, t_stack **b, char **line, int len)
{
    free_stack(a);
    free_stack(b);
    free_arg(line);
    exit(0);
}

int main(int ac, char **av)
{
    t_all *all;
    int i;

    if (ac < 2)
        exit(1);
    else
    {
        all = initial(ac, all);
        if (ac == 2)
            all->split = ft_split(av[1], ' ');
        else
            all->split = &av[1];
        check_replicat(all->split);
        check_ascii(all->split);
        all->a = put_in_list(all, all->split);
        all->len = size_list(all->a);
        while ((get_next_line(0, &all->line)))
        {
            checker_pars(&all->a, &all->b, all->len, all->line);
            free_arg(&(all->line));
        }
    }
    if (all->line[0] == '\0' || all->line[0] == '\n')
    {
        if (check_sort(&all->a, all->len) == 1)
            ft_putstr_fd("OK\n", 1);
        else
            ft_putstr_fd("KO\n", 1);
        the_end(&all->a, &all->b, &all->line, all->len);
    }
}

// int main(int ac, char **av)
// {
//     t_stack *a;
//     t_stack *b;

//     if (first_errors(ac, av) && check_ascii(av))
//     {
//         puts("---------Printing list Start--------");
//         a = put_in_list(av);
//         print_list(a);
//         puts("------- sa : Swap 2 first element---");
//          swap_stack(&a);
//         print_list(a);
//         puts("----------- Rotate stack ------------");
//          r_stack(&a);
//         print_list(a);
//         puts("------- Reverse Roate stack --------");
//         rr_stack(&a);
//         print_list(a);
//         puts("----------- Push stack --------------");
//         push_stack(&a, &b);
//         push_stack(&a, &b);
//         push_stack(&a, &b);
//         push_stack(&a, &b);
//         puts("pb pb pb pb\n");
//         puts(" ----------- a  ---------------- \n");
//         print_list(a);
//         puts(" ----------- b---------------- \n");
//         print_list(b);
//     }
// }