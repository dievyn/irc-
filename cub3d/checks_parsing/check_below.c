/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_below.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_below_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] && detect_map(map[i]) == 0)
		i++;
	if (!map[i])
		return (ft_printf(2, "Error\nNo map detected.\n"));
	while (map[i] && detect_map(map[i]) == 1)
		i++;
	if (map[i])
		return (ft_printf(2, "Error\nInformation might be stored below map.\n"
				"Please check that your is last in file.\n"));
	return (0);
}
