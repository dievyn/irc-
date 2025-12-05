/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_textures(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i] && detect_empty(map[i]) != 0)
			i++;
		j += skip_space(map[i]);
		if (ft_strncmp(&map[i][j], "NO ", 3) == 0
			|| ft_strncmp(&map[i][j], "SO ", 3) == 0
			|| ft_strncmp(&map[i][j], "EA ", 3) == 0
			|| ft_strncmp(&map[i][j], "WE ", 3) == 0)
		{
			j += 3;
			j += skip_space(&map[i][j]);
			if (!map[i][j])
				return (ft_printf(2, "Error\nMissing file path on line %d.\n",
						i + 1));
		}
		i++;
	}
	return (0);
}
