/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/05 20:48:06 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int check_sort(t_stack **A);

void print_list(t_stack *ptr)
{
    t_stack *tmp;
    tmp = ptr;
    while (ptr != NULL)
    {
        printf("[%d]->", ptr->number);
        ptr = ptr->next;
    }
    puts("\n");
    ptr = tmp;
    return;
}

int main(int ac, char **av)
{
    t_stack *A;
    t_stack *B;
    char *line = NULL;

    A = NULL;
    B = NULL;

    if (first_errors(ac, av) && check_ascii(av))
        A = put_in_list(av);

    while (1)
    {
        line = malloc(sizeof(char) * (BUFFER));
        read(0, line, BUFFER);
        if (!line)
            exit(0);
        if (!ft_strcmp(line, "sa\n"))
        {
            swap_stack(&A);
            // puts("------- sa : Swap 2 first element---\n");
            print_list(A);
        }
        if (!ft_strcmp(line, "ra\n"))
        {
            r_stack(&A);
            // puts("----------- Rotate stack A ------------\n");
            print_list(A);
        }
        if (!ft_strcmp(line, "rra\n"))
        {
            rr_stack(&A);
            // puts("----------- Reverse Rotate stack A ------------\n");
            print_list(A);
        }
        /*****************************************/

        if (!ft_strcmp(line, "sb\n"))
        {
            if (B)
            {
                swap_stack(&B);
                // puts("------- sb : Swap 2 first element---");
                print_list(B);
            }
            else
                ft_putstr_fd("B : empty :/", 2);
        }
        if (!ft_strcmp(line, "rb\n"))
        {
            if (B)
            {
                r_stack(&B);
                // puts("------- rotate b---");
                print_list(B);
            }
            else
                ft_putstr_fd("B : empty :/", 2);
        }
        if (!ft_strcmp(line, "rrb\n"))
        {
            if (B)
            {
                rr_stack(&B);
                // puts("------- reverse rotation ---");
                print_list(B);
            }
            else
                ft_putstr_fd("B : empty :/", 2);
        }
        if (!ft_strcmp(line, "pa\n"))
        {
            push_stack(&A, &B);
            // puts("-------push_stack in B----------\n");
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
                // puts("-------push_stack in A----------\n");
                puts("A : ");
                print_list(A);
                puts("B : ");
                print_list(B);
            }
            else
                ft_putstr_fd("B : empty :/", 2);
        }
        /*****************************************/
        if (!ft_strcmp(line, "ss\n"))
        {
            if (B)
            {
                ss(&A, &B);
                puts("A : ");
                print_list(A);
                puts("B : ");
                print_list(B);
            }
            else
                ft_putstr_fd("B : empty :/", 2);
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
                ft_putstr_fd("B : empty :/", 2);
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
                ft_putstr_fd("B : empty :/", 2);
        }

        /*****************************************/

        if (!ft_strcmp(line, "\0"))
        {
            if (check_sort(&A) == 1)
                ft_putstr_fd("ok\n", 1);
            else
                ft_putstr_fd("ko\n", 1);
            // free_stack(A);
            // free_stack(B);
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