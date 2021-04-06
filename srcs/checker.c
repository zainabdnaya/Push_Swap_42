/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/06 12:06:24 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *A;
    t_stack *B;
    char *line;
    t_stack *C;

    line = NULL;
    A = NULL;
    B = NULL;
    C = NULL;
    if (first_errors(ac, av) && check_ascii(av))
    {
        A = put_in_list(av);
        C = put_in_list(av);
    }
    sort(C);
    puts("-------------sorted-----------\n");
    print_list(C);
    puts("-------------sorted-----------\n");
    while (1)
    {
        line =(char *) malloc(sizeof(char) * (BUFFER));
        read(0, line, BUFFER);
        if (!line)
            exit(0);
        if (!ft_strcmp(line, "sa\n"))
        {
            swap_stack(&A);
            print_list(A);
            sort_result(A);
        }
        if (!ft_strcmp(line, "ra\n"))
        {
            r_stack(&A);
            print_list(A);
            sort_result(A);
        }
        if (!ft_strcmp(line, "rra\n"))
        {
            rr_stack(&A);
            print_list(A);
            sort_result(A);
        }
        /*****************************************/
        if (!ft_strcmp(line, "sb\n"))
        {
            if (B)
            {
                swap_stack(&B);
                print_list(B);
            }
            else
                ft_putstr_fd("B : empty \n", 2);
            sort_result(A);
        }
        if (!ft_strcmp(line, "rb\n"))
        {
            if (B)
            {
                r_stack(&B);
                print_list(B);
            }
            else
                ft_putstr_fd("B : empty \n", 2);
            sort_result(A);
        }
        if (!ft_strcmp(line, "rrb\n"))
        {
            if (B)
            {
                rr_stack(&B);
                print_list(B);
            }
            else
                ft_putstr_fd("B : empty \n", 2);
            sort_result(A);
        }
        /*****************************************/

        if (!ft_strcmp(line, "pa\n"))
        {
            push_stack(&A, &B);
            puts("A : ");
            print_list(A);
            puts("B : ");
            print_list(B);
        }
        if (!ft_strcmp(line, "pb\n"))
        {
            if (B)
            {
                push_stack(&B, &A);
                puts("A : ");
                print_list(A);
                puts("B : ");
                print_list(B);
            }
            else
                ft_putstr_fd("B : empty \n", 2);
            sort_result(A);
        }
        /*****************************************/
        if (!ft_strcmp(line, "ss\n"))
        {
            if (B)
            {
                ss(&A, &B);
                puts("A:  ");
                print_list(A);
                puts("B : ");
                print_list(B);
            }
            else
                ft_putstr_fd("B : empty \n", 2);
            sort_result(A);
        }
        if (!ft_strcmp(line, "rr\n"))
        {
            if (B)
            {
                rr(&A, &B);
                puts("A : ");
                print_list(A);
                puts("B : ");
                print_list(B);
            }
            else
                ft_putstr_fd("B : empty \n", 2);
            sort_result(A);

        }
        if (!ft_strcmp(line, "rrr\n"))
        {
            if (B)
            {
                rrr(&A, &B);
                puts("A : ");
                print_list(A);
                puts("B : ");
                print_list(B);
            }
            else
                ft_putstr_fd("B : empty \n", 2);
            sort_result(A);
        }
        /*****************************************/

        if (line[0] == '\0')
        {
            if (check_sort(&A) == 1)
                ft_putstr_fd("Ok\n", 2);
            else
                ft_putstr_fd("KO\n", 2);

            exit(0);
        }
        free_arg(&line);
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