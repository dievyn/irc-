/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:29:27 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/22 09:29:29 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long		i;
	char				*desttt;
	char				*sc;

	i = 0;
	if (n == 0 || (dest == 0 && src == 0))
		return (dest);
	desttt = (char *)dest;
	sc = (char *)src;
	while (i < n)
	{
		desttt[i] = sc[i];
		i++;
	}
	return (dest);
}
