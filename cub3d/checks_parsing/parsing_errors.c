/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	detect_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isprint(str[i]) == 0)
		i++;
	if (str[i])
		return (0);
	else
		return (1);
}

int	parsing_errors(char **map)
{
	if (map[0] == NULL)
		return (ft_printf(2, "Error\nEmpty file.\n"), -1);
	if (unknown_char(map) != 0)
		return (-1);
	if (check_below_map(map) != 0)
		return (-1);
	if (check_dups(map) != 0)
		return (-1);
	if (check_colors(map) != 0)
		return (-1);
	if (check_textures(map) != 0)
		return (-1);
	return (0);
}
