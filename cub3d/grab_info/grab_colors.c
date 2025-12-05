/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_colors.c                                      :+:      :+:    :+:   */
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

static int	grab_colors2(char *str, t_parsing *parsing)
{
	int		i;
	int		count;
	int		tab[3];
	char	*num_str;

	i = 1;
	count = 0;
	while (count < 3)
	{
		i += skip_space(&str[i]);
		num_str = ft_substr(&str[i], 0, while_num(&str[i]));
		if (!num_str)
			return (-1);
		tab[count] = ft_atoi(num_str);
		free(num_str);
		count++;
		i += while_num(&str[i]);
		i += skip_space(&str[i]) + 1;
	}
	if (str[0] == 'F')
		parsing->floor = decrypt_colors(tab);
	if (str[0] == 'C')
		parsing->cieling = decrypt_colors(tab);
	return (0);
}

int	grab_colors(char **map, t_parsing *parsing)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i] && detect_empty(map[i]) != 0)
			i++;
		j += skip_space(&map[i][j]);
		if (ft_strncmp(&map[i][j], "F ", 2) == 0
			|| ft_strncmp(&map[i][j], "C ", 2) == 0)
			if (grab_colors2(&map[i][j], parsing) != 0)
				return (ft_printf(2, "Unexpected error occured.\n"));
		i++;
	}
	return (0);
}
