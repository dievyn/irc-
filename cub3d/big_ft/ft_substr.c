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
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, int start, int len)
{
	char	*str2;
	int		i;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str2 = (char *)malloc ((len + 1) * sizeof (char));
	if (str2 == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		str2[i] = s[start];
		i++;
		start++;
	}
	str2[i] = '\0';
	return (str2);
}
