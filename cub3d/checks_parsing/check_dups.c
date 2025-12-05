/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	len_id(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isprint(str[i]) != 0)
		i++;
	return (i);
}

static int	check_similar(char *target, char **map, int line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] && detect_map(map[i + 1]) == 0)
	{
		j = 0;
		while (map[i] && detect_empty(map[i]) != 0)
			i++;
		j += skip_space(map[i]);
		if (ft_strncmp(&map[i][j], target, ft_strlen(target)) == 0)
		{
			free(target);
			return (ft_printf(2, "Error\nDuplicate detected on line %d.\n",
					++line + i));
		}
		i++;
	}
	free(target);
	return (0);
}

int	detect_map(char *str)
{
	int	i;

	i = skip_space(str);
	if (str[i] == '1' || str[i] == '0')
		return (1);
	return (0);
}

int	check_dups(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i] && detect_empty(map[i]) != 0)
			i++;
		if (detect_map(map[i]) == 1)
			break ;
		if (map[i])
			j += skip_space(map[i]);
		if (check_similar(ft_substr(map[i], j, len_id(&map[i][j])),
			&map[i + 1], i + 1) != 0)
			return (-1);
		count++;
		i++;
	}
	if (count != 6)
		return (ft_printf(2, "Error\nMissing id.\n"));
	return (0);
}
// deuxieme essai
