/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:40:37 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/25 11:40:38 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_sizenbr(long int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_fill(char *str, long int n, int size)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		str[i] = 48;
		str[i + 1] = 0;
		return (str);
	}
	while (i != size - 1)
		i++;
	str[i] = '\0';
	i--;
	while (n > 0)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	int			size;
	int long	nb;

	nb = (int long)n;
	i = 0;
	if (n < 0)
	{
		nb = nb * -1;
		size = ft_sizenbr(nb) + 2;
		str = (char *) malloc (size * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = 45;
	}
	else
	{
		size = ft_sizenbr(nb) + 1;
		str = (char *) malloc (size * sizeof(char));
	}
	if (str == NULL)
		return (NULL);
	ft_fill(str, nb, size);
	return (str);
}
/*
int main (void)
{
	int i = 0;
	char *str = ft_itoa(53773);
	while(str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	free (str);
}*/
