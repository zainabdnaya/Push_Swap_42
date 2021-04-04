/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:45:40 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/04 11:54:52 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void    refer(char **b)
{
    // char **s;

    *b = "world";

    // b = s;
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