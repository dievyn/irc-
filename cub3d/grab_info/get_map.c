/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	check_characters(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && (ft_isprint(str[i]) == 0
				|| str[i] == '1' || str[i] == '0'
				|| str[i] == 'N' || str[i] == 'S'
				|| str[i] == 'E' || str[i] == 'W'
				|| str[i] == 'D'))
			i++;
		else
			return (ft_printf(2, "Error\nUnknown character found in map.\n"));
	}
	return (0);
}

static int	check_map(t_parsing *parsing, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (check_characters(map[i]) != 0)
			return (-1);
		i++;
	}
	if (check_spawn(map) != 0)
		return (-1);
	grab_spawn(map, parsing);
	if (fill_me_up(map, parsing->spawn[0], parsing->spawn[1]) != 0)
		return (-1);
	return (0);
}

static int	detect_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isprint(str[i]) == 0)
		i++;
	if (str[i] && str[i] == '1')
		return (0);
	return (1);
}

char	**get_map(t_parsing *parsing, char **tab)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] && detect_line(tab[i]) != 0)
		i++;
	while (tab[i + j])
		j++;
	map = ft_calloc (j + 1, sizeof (char *));
	j = 0;
	while (tab[i])
	{
		map[j] = ft_substr(tab[i], 0, ft_strlen(tab[i]) - 1);
		i++;
		j++;
	}
	if (check_map(parsing, map) != 0)
		return (free_tab(map), NULL);
	return (map);
}
