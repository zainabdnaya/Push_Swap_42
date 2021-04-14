/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/14 16:07:52 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char **av)
{
    t_all *all;
    int i;

    i = 0;
    if (ac < 2)
        exit(1);
    else
    {
        all = initial(ac, all);
        if (!ft_strcmp(av[1], "-v"))
        {
            all->print = 1;
            if (ac == 3)
                all->split = ft_split(av[2], ' ');
            else
                all->split = &av[2];
        }
        else
        {
            if (ac == 2)
                all->split = ft_split(av[1], ' ');
            else
                all->split = &av[1];
        }
        check_replicat(all->split);
        check_ascii(all->split);
        all->a = put_in_list(all, all->split);
        all->len = size_list(all->a);
        if (ac == 2 || ac == 3)
        {
            while (all->split[i])
            {
                free_arg(&all->split[i]);
                all->split[i] = NULL;
                i++;
            }
            free_arg(all->split);
            all->split = NULL;
        }
        while ((get_next_line(0, &all->line)))
        {
            checker_pars(&all->a, &all->b, all->len, all->line);
            free_arg(&(all->line));
            if (all->print == 1)
            {
                system("clear");
                print_all(all->a, all->b);
            }
        }
        if (all->line[0] == '\0' || all->line[0] == '\n')
        {
            if (check_sort(&all->a, all->len) == 1)
                ft_putstr_fd("OK\n", 1);
            else
                ft_putstr_fd("KO\n", 1);
            free_stack(&all->a);
            the_end(&all->a, &all->b, &all->line, all);
        }
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