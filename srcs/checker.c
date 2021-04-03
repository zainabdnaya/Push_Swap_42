/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/03 13:27:32 by zdnaya           ###   ########.fr       */
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
// void print_2_stack(t_stack *ptr,t_stack *ptr1)
// {
//     t_stack *tmp;
//     t_stack *tmp1;
//     // printf(" -------Printing list Start------- \n");
//     tmp = ptr;
//     tmp1 = ptr;

//     printf("[A]\t\t\t[B]\n");
//     puts("\n");
//     while (ptr != NULL || ptr1 != NULL )
//     {
//         printf("[%d]\t\t\t[%d]\n", ptr->number,ptr1->number);
//         printf("↑↓\t\t\t↑↓\n");
//         if(ptr)
//             ptr = ptr->next;
//         if ( ptr1)
//             ptr1 = ptr1->next;
//     }
//     ptr = tmp;
//     ptr1 = tmp1;
//     // printf(" -------Printing list End------- \n");

//     return;
// }

int main(int ac, char **av)
{
    t_stack *A;
    t_stack *B;

    B = NULL;
    if (first_errors(ac, av) && check_ascii(av))
    {
        // puts("---------Printing list Start--------");
        A = put_in_list(av);
        // print_list(A);
        // puts("------- sa : Swap 2 first element---");
        // A = swap_stack(A);
        // print_list(A);
        // puts("----------- Roate stack ------------");
        // A = rotate_stack(A);
        // print_list(A);
        // puts("------- Reverse Roate stack --------");
        // A = reverse_stack(A);
        // print_list(A);
        puts("----------- Push stack --------------");
        push_stack(A,B);
        // printf("\n[A]\n");
        // print_list(A);
        // printf("\n[B]\n");
        // print_list(B);
    }
}