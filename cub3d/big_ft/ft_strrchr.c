/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:31:15 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/22 09:31:17 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (c > 127)
	{
		while (c > 127)
		{
			c = c - 128;
		}
	}
	i = 0;
	while (s[i] != 0)
		i++;
	if (c == 0)
		return ((char *)&s[i]);
	while (s[i] != c && i > 0)
		i--;
	if (s[i] == c)
		return ((char *)&s[i]);
	else
		return (NULL);
}
