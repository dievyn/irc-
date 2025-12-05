/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	while_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]) != 0)
		i++;
	return (i);
}

static int	catch_num(char *str, int line)
{
	long int	num;
	char		*num_str;

	num_str = ft_substr(str, 0, while_num(str));
	if (!num_str)
		return (ft_printf(2, "Unexpected error occured.\n"));
	num = ft_atol(num_str);
	free(num_str);
	if (num > 2147483647 || num < -2147483648)
		return (ft_printf(2, "Error\nInt overflow on line %d.\n", ++line));
	if (num < 0 || num > 255)
		return (ft_printf(2, "Error\nInvalid color number on line %d.\n",
				++line));
	return (0);
}

static int	check_num_format(char *str, int line)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (str[i])
	{
		i += skip_space(&str[i]);
		if (ft_isdigit(str[i]) == 0)
			return (ft_printf(2, "Error\nInvalid color format on line %d.\n",
					++line));
		if (catch_num(&str[i], line) != 0)
			return (-1);
		i += while_num(&str[i]);
		count++;
		i += skip_space(&str[i]);
		if (str[i] && str[i] != ',')
			return (ft_printf(2, "Error\nInvalid color format on line %d.\n",
					++line));
		i++;
	}
	if (count != 3)
		return (ft_printf(2, "Error\nInvalid color format on line %d.\n",
				++line));
	return (0);
}

int	check_colors(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i] && detect_empty(map[i]) != 0)
			i++;
		j += skip_space(&map[i][0]);
		if (map[i][j] == 'F' || map[i][j] == 'C')
			if (check_num_format(&map[i][j], i) != 0)
				return (-1);
		i++;
	}
	return (0);
}
