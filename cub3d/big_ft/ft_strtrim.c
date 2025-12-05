/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:28:32 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/28 15:28:41 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

static int	ft_check(char c, char const *set)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (set[i] != '\0')
	{
		if (set[i] != c)
			x++;
		i++;
	}
	if (x == ft_strlen(set))
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	j = 0;
	while (ft_check(s1[i], set) == 0)
		i++;
	j = ft_strlen(s1);
	while (ft_check(s1[j - 1], set) == 0)
		j--;
	if (j - i + 1 < 0)
	{
		copy = (char *) malloc (1 * sizeof (char));
		if (copy == NULL)
			return (NULL);
		copy[0] = '\0';
		return (copy);
	}
	copy = (char *) malloc ((j - i) + 1 * sizeof (char));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, &s1[i], (j - i + 1));
	return (copy);
}
