/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_use.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:33:49 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/02 15:35:16 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i;

    i = 0;
    if ((!s1 || !s2))
        return (-1);
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    if (((s1[i] == '\0' && s2[i] != '\0') || (s2[i] == '\0' && s1[i] != '\0')))
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    return (0);
}