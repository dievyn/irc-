/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:25:13 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/22 09:25:21 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{	
	int	i;
	int	res;
	int	c;

	i = 0;
	res = 0;
	c = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			c++;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] > 47 && nptr[i] < 58)
	{
		res = res * 10;
		res = res + (nptr[i] - 48);
		i++;
	}
	if (c == 1)
		return (res * -1);
	return (res);
}
