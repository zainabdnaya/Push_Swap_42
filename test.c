/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:45:40 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/05 14:12:01 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_test{
    int data;
    struct s_test *next;
} t_test;

void refer(char **b)
{

    *b = "world";

}

int main()
{
    char *p;

    p = "hello";
    printf("befor : ==>%s\n", p);
    refer(&p);
    printf("after : ==>%s\n", p);
    return 0;
}