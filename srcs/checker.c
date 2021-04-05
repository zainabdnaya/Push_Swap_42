/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/05 14:03:48 by zdnaya           ###   ########.fr       */
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

    A = NULL;
    B = NULL;
    if (first_errors(ac, av) && check_ascii(av))
    {
        A = put_in_list(av);
        print_list(A);
        // rotate_stack(&A);
        // swap_stack(&A);
        // first(&A, &B);
        // sort(A);
        puts(" ----------- A  ---------------- \n");
        print_list(A);
        puts(" ----------- B ---------------- \n");
        print_list(B);
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