/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:30:56 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/22 09:30:58 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned long	i;
	int				j;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[i] != '\0' && i <= len)
	{
		j = 0;
		while (big[i] == little[j] && i <= len)
		{
			if (little[j + 1] == '\0' && i < len)
				return ((char *)&big[i - j]);
			i++;
			j++;
		}
		i = i + 1 - j;
	}
	return (NULL);
}
