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
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	char	*cpy;

	i = 0;
	str = (char *) s;
	cpy = (char *) malloc (ft_strlen(s) + 1 * sizeof (char));
	if (cpy == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		cpy[i] = f(i, str[i]);
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
