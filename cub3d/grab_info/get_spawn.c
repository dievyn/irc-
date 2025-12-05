/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	detect_spawn(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == 'N' || str[i] == 'S'
				|| str[i] == 'E' || str[i] == 'W'))
			return (1);
		i++;
	}
	return (0);
}

void	grab_spawn(char **map, t_parsing *parsing)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (detect_spawn(map[i]) == 0)
		i++;
	while (map[i][j] && map[i][j] != 'N' && map[i][j] != 'S'
		&& map[i][j] != 'E' && map[i][j] != 'W')
		j++;
	parsing->spawn[0] = i;
	parsing->spawn[1] = j;
	parsing->spawn_dir = map[i][j];
}

int	check_spawn(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		if (detect_spawn(map[i]) == 1)
			count++;
		i++;
	}
	if (count != 1)
		return (ft_printf(2, "Error\nInvalid spawn.\n"));
	return (0);
}
