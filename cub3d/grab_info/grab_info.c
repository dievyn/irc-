/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	grab_info(char **map, t_parsing *parsing)
{
	if (grab_textures(map, parsing) != 0)
		return (-1);
	if (grab_colors(map, parsing) != 0)
		return (-1);
	parsing->map = get_map(parsing, map);
	if (parsing->map == NULL)
		return (-1);
	return (0);
}
