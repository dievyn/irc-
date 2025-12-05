/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:00:35 by tdenis            #+#    #+#             */
/*   Updated: 2025/10/02 15:00:35 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copy_tab(char **tab)
{
	char	**copy;
	int		len;
	int		i;

	i = 0;
	len = tab_len(tab);
	copy = ft_calloc(len + 1, sizeof (char **));
	while (i < len)
	{
		copy[i] = ft_strdup(tab[i]);
		i++;
	}
	return (copy);
}
