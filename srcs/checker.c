/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/08 12:56:26 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int checker_1(t_stack *A,t_stack *B,int m,char *line)
// {
// }

void the_end(t_stack **A, t_stack **B, char **line, int len)
{
    free_stack(A);
    free_stack(B);
    free_arg(line);
    exit(0);
}

int main(int ac, char **av)
{
    t_stack *A;
    t_stack *B;
    char *line;
    t_stack *C;
    int len;
    int m;

    line = NULL;
    A = NULL;
    B = NULL;
    C = NULL;
    m = 0;
    if (first_errors(ac, av) && check_ascii(av))
    {
        A = put_in_list(av);
        C = put_in_list(av);
    }
    // sort(C);
    // ft_putstr_fd("-----sorted---\n", 0);
    // print_list(C);
    // ft_putstr_fd("-----sorted---\n", 0);
    len = size_list(A);
    while (1)
    {
        line = (char *)malloc(sizeof(char) * (BUFFER));
        read(0, line, BUFFER);
        if (line[0] == '\0' || line[0] == '\n')
        {
            if (check_sort(&A, len) == 1)
                ft_putstr_fd("OK\n", 1);
            else
                ft_putstr_fd("KO\n", 1);
            the_end(&A, &B, &line, len);
        }
        if (!ft_strcmp(line, "sa\n"))
            swap_stack(&A);
        if (!ft_strcmp(line, "ra\n"))
            r_stack(&A);
        if (!ft_strcmp(line, "rra\n"))
            rr_stack(&A);
        if (!ft_strcmp(line, "sb\n"))
            swap_stack(&B);
        if (!ft_strcmp(line, "rb\n"))
            r_stack(&B);
        if (!ft_strcmp(line, "rrb\n"))
            rr_stack(&B);
        if (!ft_strcmp(line, "pb\n"))
            push_stack(&A, &B);
        if (!ft_strcmp(line, "pa\n"))
            push_stack(&B, &A);
        if (!ft_strcmp(line, "ss\n"))
            ss(&A, &B);
        if (!ft_strcmp(line, "rr\n"))
            rr(&A, &B);
        if (!ft_strcmp(line, "rrr\n"))
            rrr(&A, &B);
        // if (check_sort(&A, len) == 1)
        // {
        //     ft_putstr_fd("OK\n", 1);
        //     the_end(&A, &B, &line, len);
        // }
        free_arg(&line);
        print_all(A, B);
    }
}

// int main(int ac, char **av)
// {
//     t_stack *A;
//     t_stack *B;

//     if (first_errors(ac, av) && check_ascii(av))
//     {
//         puts("---------Printing list Start--------");
//         A = put_in_list(av);
//         print_list(A);
//         puts("------- sa : Swap 2 first element---");
//          swap_stack(&A);
//         print_list(A);
//         puts("----------- Rotate stack ------------");
//          r_stack(&A);
//         print_list(A);
//         puts("------- Reverse Roate stack --------");
//         rr_stack(&A);
//         print_list(A);
//         puts("----------- Push stack --------------");
//         push_stack(&A, &B);
//         push_stack(&A, &B);
//         push_stack(&A, &B);
//         push_stack(&A, &B);
//         puts("pb pb pb pb\n");
//         puts(" ----------- A  ---------------- \n");
//         print_list(A);
//         puts(" ----------- B ---------------- \n");
//         print_list(B);
//     }
// }