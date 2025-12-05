/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unknown.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_what_str(str[i], "NSEW01D \n") != 0)
			return (-1);
		i++;
	}
	return (0);
}

static int	packed_if(char *str)
{
	if (str && ft_strncmp(str, "F ", 2) != 0
		&& ft_strncmp(str, "C ", 2) != 0
		&& ft_strncmp(str, "NO ", 3) != 0
		&& ft_strncmp(str, "SO ", 3) != 0
		&& ft_strncmp(str, "WE ", 3) != 0
		&& ft_strncmp(str, "EA ", 3) != 0
		&& str[0] != '1' && str[0] != '0')
		return (-1);
	return (0);
}

int	unknown_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i] && detect_empty(map[i]) != 0)
			i++;
		if (!map[i])
			break ;
		j += skip_space(map[i]);
		if (packed_if(&map[i][j]) == -1)
			return (ft_printf(2, "Error\nUnexpected id detected on line %d.",
					i + 1));
		else if ((map[i][j] == '1' || map[i][j] == '0')
			&& check_line(map[i]) != 0)
			return (ft_printf(2, "Error\nUnexpected character detected on line "
					"%d.", i + 1));
		i++;
	}
	return (0);
}
