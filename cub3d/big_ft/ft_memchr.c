/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:29:14 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/22 09:29:16 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*sc;
	unsigned char	cc;

	i = 0;
	sc = (unsigned char *)s;
	cc = (unsigned char )c;
	while (i < n)
	{
		if (sc[i] == cc)
			return ((unsigned char *)&s[i]);
		i++;
	}
	return (NULL);
}
