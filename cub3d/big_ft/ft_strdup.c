/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:27:05 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/30 11:27:07 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

char	*ft_strdup(char *str)
{
	char	*copy;
	size_t	l;

	l = ft_strlen(str) + 1;
	copy = ft_calloc(l + 1, sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, str, l);
	return (copy);
}
