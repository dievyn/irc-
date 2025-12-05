/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
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

//	if invalid, returns 0
int	ft_isprint(int c)
{
	if (c <= 32 || c >= 127)
		return (0);
	else
		return (16384);
}
