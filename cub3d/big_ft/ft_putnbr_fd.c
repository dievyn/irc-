/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:37:55 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/25 11:37:57 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_sizenbr(long int n)
{
	int	i;
	int	s;

	i = 1;
	s = 1;
	while (n > 9)
	{
		n = n / 10;
		i = i * 10;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		s;
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n < 0 && n != -2147483648)
	{
		n = n * -1;
		write(fd, "-", 1);
	}
	s = ft_sizenbr(n);
	while (s > 0 && n != -2147483648)
	{
		c = (n / s) + 48;
		n = n - ((c - 48) * s);
		s = s / 10;
		write(fd, &c, 1);
	}
}
