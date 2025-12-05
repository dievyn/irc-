/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	is_what_str(char c, char *exceptions)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (exceptions[i])
	{
		if (c == exceptions[i])
			check++;
		i++;
	}
	if (check == 0)
		return (-1);
	return (0);
}

static int	check_surroundings(char **map, int i, int j)
{
	if (i == 0 || j == 0)
		return (-1);
	if (i == tab_len(map) - 1)
		return (-1);
	if (j == ft_strlen(map[i]))
		return (-1);
	if (j > ft_strlen(map[i - 1]) || j > ft_strlen(map[i + 1]))
		return (-1);
	if (is_what_str(map[i][j], " D0NSEW") != 0
		|| is_what_str(map[i][j + 1], " D0NSEW1x") != 0
		|| is_what_str(map[i][j - 1], " D0NSEW1x") != 0
		|| is_what_str(map[i + 1][j], " D0NSEW1x") != 0
		|| is_what_str(map[i - 1][j], " D0NSEW1x") != 0)
		return (-1);
	return (0);
}

static int	flood_fill(char **map, int i, int j)
{
	if (check_surroundings(map, i, j) != 0)
		return (-1);
	map[i][j] = 'x';
	if (map[i][j + 1] && map[i][j + 1] != '1' && map[i][j + 1] != 'x')
		if (flood_fill(map, i, j + 1) == -1)
			return (-1);
	if (j > 0 && map[i][j - 1] && map[i][j - 1] != '1' && map[i][j - 1] != 'x')
		if (flood_fill(map, i, j - 1) == -1)
			return (-1);
	if (map[i + 1] && map[i + 1][j] != '1' && map[i + 1][j] != 'x')
		if (flood_fill(map, i + 1, j) == -1)
			return (-1);
	if (i > 0 && map[i - 1] && map[i - 1][j] != '1' && map[i - 1][j] != 'x')
		if (flood_fill(map, i - 1, j) == -1)
			return (-1);
	return (0);
}

int	fill_me_up(char **map, int i, int j)
{
	char	**copy;

	copy = copy_tab(map);
	if (flood_fill(copy, i, j) == -1)
		return (free_tab(copy), ft_printf(2, "Error\nInvalid map.\n"));
	free_tab(copy);
	return (0);
}
