/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	grab_id(char *str, char **result)
{
	char	*str2;
	int		fd;

	str2 = ft_substr(str, 3, ft_strlen(str) - 4);
	*result = ft_strtrim(str2, " 	\a\b\t\n\v\f\r");
	free(str2);
	str2 = ft_substr(*result, ft_strlen(*result) - 4, ft_strlen(*result));
	if (ft_strncmp(str2, ".xpm", 4) != 0)
		return (ft_printf(2, "Error\nFile is not a \".xpm\" extension.\n"),
			free(str2), free(*result), *result = NULL, -1);
	free(str2);
	fd = open(*result, O_RDONLY);
	if (fd == -1)
		return (ft_printf(2, "Error\nNo existing file \"%s\" detected.\n",
				*result), free(*result), *result = NULL, -1);
	close (fd);
	return (0);
}

static int	catch_id(char *str, t_parsing *parsing)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
		if (grab_id(str, &parsing->no) != 0)
			return (-1);
	if (ft_strncmp(str, "SO ", 3) == 0)
		if (grab_id(str, &parsing->so) != 0)
			return (-1);
	if (ft_strncmp(str, "EA ", 3) == 0)
		if (grab_id(str, &parsing->ea) != 0)
			return (-1);
	if (ft_strncmp(str, "WE ", 3) == 0)
		if (grab_id(str, &parsing->we) != 0)
			return (-1);
	return (0);
}

int	grab_textures(char **map, t_parsing *parsing)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i] && detect_empty(map[i]) != 0)
			i++;
		while (map[i][j] && ft_isprint(map[i][j]) == 0)
			j++;
		if (ft_strncmp(&map[i][j], "NO ", 3) == 0
			|| ft_strncmp(&map[i][j], "SO ", 3) == 0
			|| ft_strncmp(&map[i][j], "EA ", 3) == 0
			|| ft_strncmp(&map[i][j], "WE ", 3) == 0)
			if (catch_id(&map[i][j], parsing) != 0)
				return (-1);
		i++;
	}
	return (0);
}
