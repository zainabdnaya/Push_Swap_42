/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 00:13:19 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/20 12:17:54 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

void		ft_putstr_fd(char *s, int fd)
{
	int			i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			n = n * (-1);
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(n, fd);
		}
	}
	else
	{
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}


void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}