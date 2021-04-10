/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/10 14:49:27 by zdnaya           ###   ########.fr       */
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
    t_stack *a;
    t_stack *b;
    char *line;
    t_stack *C;
    int len;
    int m;

    line = NULL;
    a = NULL;
    b= NULL;
    C = NULL;
    m = 0;
    if (first_errors(ac, av) && check_ascii(av))
    {
        a = put_in_list(av);
        C = put_in_list(av);
    }
    // sort(C);
    // ft_putstr_fd("-----sorted---\n", 0);
    // print_list(C);
    // ft_putstr_fd("-----sorted---\n", 0);
    len = size_list(a);
    while (1)
    {
        line = (char *)malloc(sizeof(char) * (BUFFER));
        read(0, line, BUFFER);
        if (line[0] == '\0' || line[0] == '\n')
        {
            if (check_sort(&a, len) == 1)
                ft_putstr_fd("OK\n", 1);
            else
                ft_putstr_fd("KO\n", 1);
            the_end(&a, &b, &line, len);
        }
        if (!ft_strcmp(line, "sa\n"))
            swap_stack(&a);
        if (!ft_strcmp(line, "ra\n"))
            r_stack(&a);
        if (!ft_strcmp(line, "rra\n"))
            rr_stack(&a);
        if (!ft_strcmp(line, "sb\n"))
            swap_stack(&b);
        if (!ft_strcmp(line, "rb\n"))
            r_stack(&b);
        if (!ft_strcmp(line, "rrb\n"))
            rr_stack(&b);
        if (!ft_strcmp(line, "pb\n"))
            push_stack(&a, &b);
        if (!ft_strcmp(line, "pa\n"))
            push_stack(&b, &a);
        if (!ft_strcmp(line, "ss\n"))
            ss(&a, &b);
        if (!ft_strcmp(line, "rr\n"))
            rr(&a, &b);
        if (!ft_strcmp(line, "rrr\n"))
            rrr(&a, &b);
        // if (check_sort(&a, len) == 1)
        // {
        //     ft_putstr_fd("OK\n", 1);
        //     the_end(&a, &b, &line, len);
        // }
        free_arg(&line);
        // print_all(a, B);
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