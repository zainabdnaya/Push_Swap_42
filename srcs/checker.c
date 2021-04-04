/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/04 15:42:17 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_stack *ptr)
{
    t_stack *tmp;
    // printf(" -------Printing list Start------- \n");
    tmp = ptr;
    while (ptr != NULL)
    {
        printf("[%d]\n", ptr->number);
        printf("↑↓\n");
        ptr = ptr->next;
    }
    ptr = tmp;
    // printf(" -------Printing list End------- \n");

    return;
}

int main(int ac, char **av)
{
    t_stack *A;
    t_stack *B;

    if (first_errors(ac, av) && check_ascii(av))
    {
        // puts("---------Printing list Start--------");
        A = put_in_list(av);
        print_list(A);
        puts("------- sa : Swap 2 first element---");
        A = swap_stack(A);
        print_list(A);
        puts("----------- Rotate stack ------------");
        A = rotate_stack(A);
        print_list(A);
        puts("------- Reverse Roate stack --------");
        A = reverse_stack(A);
        print_list(A);
        puts("----------- Push stack --------------");
        push_stack(&A, &B);
        push_stack(&A, &B);
        push_stack(&A, &B);
        push_stack(&A, &B);
        puts("pb pb pb pb\n");
        puts(" ----------- A  ---------------- \n");
        print_list(A);
        puts(" ----------- B ---------------- \n");
        print_list(B);
    }
}