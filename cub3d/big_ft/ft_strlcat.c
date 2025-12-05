/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:30:07 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/22 09:30:09 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
//#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	unsigned long	i;
	unsigned long	x;
	int				j;

	i = 0;
	j = 0;
	if (siz <= 0)
		return (ft_strlen(src));
	while (dst[i] != '\0')
		i++;
	x = i;
	while (i < siz - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (siz < x)
		return (ft_strlen(src) + siz);
	return (ft_strlen(src) + x);
}
