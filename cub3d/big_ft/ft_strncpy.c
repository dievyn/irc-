/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:22:18 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/30 11:22:21 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
//#include <bsd/string.h>

char	*ft_strncpy(char *dst, const char *src, int siz)
{
	int	i;

	if (siz == 0)
		return (NULL);
	if (siz > ft_strlen(src))
		siz = ft_strlen(src) + 1;
	i = 0;
	while (i < siz)
	{
		dst[i] = src[i];
		i++;
	}
	dst[siz - 1] = '\0';
	return (dst);
}
