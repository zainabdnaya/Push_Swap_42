/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/13 13:42:35 by zdnaya           ###   ########.fr       */
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
t_stack *put_in_list1(char **av)
{
    t_stack *a;
    t_stack *tmp;
    char *str;
    int i;

    i = 1;
    tmp = NULL;
    str = NULL;
    a = (t_stack *)malloc(sizeof(t_stack));
    a = NULL;
    while (av[i])
    {
        str = ft_strdup(av[i]);
        add_back(&a, tmp, str);
        free_stack(&tmp);
        free_arg(&str);
        i++;
    }
    // print_list(a);
    return (a);
}

int main(int ac, char **av)
{
    t_all *all;

    if (first_errors(ac, av) && check_ascii(av))
        all = initial(ac, av, all);
    all->a = put_in_list(all, av);
    all->len = size_list(all->a);
    while (get_next_line(0, &all->line) == 1)
    {
        checker_pars(all->a, all->b, all->len, all->line);
        free_arg(&(all->line));
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