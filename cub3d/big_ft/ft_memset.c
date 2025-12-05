/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:29:42 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/22 09:29:43 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long		i;
	char				*sc;

	i = 0;
	sc = (char *)s;
	while (i < n)
	{
		sc[i] = c;
		i++;
	}
	return (s);
}
/*
int main (void)
{
	int i = 0;
	char idk[] = "t";
	size_t size = sizeof( char ) * strlen(idk);
	ft_memset(idk, 64, size);
	while (idk[i] != '\0')
	{
		write(1, &idk[i], 1);
		i++;
	}
	write(1, "\n", 1);
//--------------------------------------------
	i = 0;
	int idk2[] = {5,52,675,7689,45,3};
	size_t size2 = sizeof( int ) * 6;
	ft_memset(idk2, 64, size2);
	while (idk2[i] != '\0')
	{
		write(1, &idk2[i], 1);
		i++;
	}
}*/
