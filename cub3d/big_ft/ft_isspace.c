/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:27:36 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/22 09:27:40 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

//	if space OR "\character", returns 0
int	ft_isspace(int c)
{
	if (c == 32 || (c >= 7 && c <= 13))
		return (0);
	else
		return (16384);
}
