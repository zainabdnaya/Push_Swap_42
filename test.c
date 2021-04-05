/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:45:40 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/05 20:49:34 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// typedef struct s_test{
//     int data;
//     struct s_test *next;
//     struct s_tes *prv;

// } t_test;


// void refer(char **b)
// {

//     *b = "world";

// }
// void print_list(t_test *ptr)
// {
//     t_test *tmp;
//     // printf(" -------Printing list Start------- \n");
//     tmp = ptr;
//     while (ptr != NULL)
//     {
//         printf("[%d]\n", ptr->data);
//         printf("↑↓\n");
//         ptr = ptr->next;
//     }
//     ptr = tmp;
//     // printf(" -------Printing list End------- \n");

//     return;
// }
// void add(t_test **head, t_test *new, int data)
// {
//     t_test *tmp;

//     new = malloc(sizeof(t_test));
//     new->data = data;
//     new->next = NULL;
//     new->prv = NULL;
//     if (*head == NULL)
//         *head = new;
//     else
//     {
//         tmp = *head;
//         while (tmp->next)
//             tmp = tmp->next;
//         tmp->next = new;
//         new->prv = tmp;
//     }
// }

// int    avreage(t_stack *A)
// {
//     int k;
//     int i;
//     int avg;
//     t_stack *tmp;

//     i = 0;
//     k = 0;
//     avg = 0;
//     tmp = A;
//     while (A != NULL)
//     {
//         k += A->number;
//         i++;
//         A = A->next;
//     }
//     A = tmp;
//     avg = (int)(k / i);
//     return (avg);
// }


// int main()
// {

//     t_test *A;
//     t_test *B;
//     t_test *C;
//     t_test *D;
//     t_test *E;

//     A = malloc(sizeof(t_test));
//     A->data = 8;
//     A->next = NULL;
//     A->prv = NULL;
//     add(&A, B, 1);
//     add(&A, C, 9);
//     add(&A, D, -4);
//     add(&A, E, -85);
//     print_list(A);
//     // while()
//     return 0;
// }