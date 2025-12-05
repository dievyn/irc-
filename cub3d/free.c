/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	free_paths(t_parsing *parsing)
{
	if (parsing->no)
		free(parsing->no);
	if (parsing->so)
		free(parsing->so);
	if (parsing->ea)
		free(parsing->ea);
	if (parsing->we)
		free(parsing->we);
	return (0);
}

int	free_parsing(t_parsing *parsing)
{
	if (parsing->map_name)
		free(parsing->map_name);
	free_paths(parsing);
	if (parsing->map)
		free_tab(parsing->map);
	return (1);
}
