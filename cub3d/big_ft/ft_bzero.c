/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:25:55 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/22 09:25:59 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned long		i;
	char				*sc;

	sc = (char *)s;
	i = 0;
	while (i < n)
	{
		sc[i] = '\0';
		i++;
	}
}
/*
void	ft_putstr(char *str)
{
	int i = 1;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main (void)
{
	char str[] = "/BMTH-NeXGEn/NeW album+";
	write(1, "1 -", 3);
	ft_putstr(str);
	bzero(str, 2);
	ft_putstr(str);
	write(1, "\n", 1);
	char str2[] = "/BMTH-NeXGEn/NeW album+";
	write(1, "2 -", 3);
	ft_putstr(str2);
	ft_bzero(str2, 2);
	ft_putstr(str2);
}*/
