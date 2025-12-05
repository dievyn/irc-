/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_infos(t_parsing *parsing)
{
	int	i;

	i = 0;
	while (parsing->map[i])
	{
		printf("%s\n", parsing->map[i]);
		i++;
	}
	printf ("\nFloor:     %d\nCieling:     %d\nNorth: %s\nSouth: %s\nEast:  %s\nWest:  %s\nSpawn: %c [%d][%d]\n",
		parsing->floor, parsing->cieling, parsing->no, parsing->so,
		parsing->ea, parsing->we, parsing->spawn_dir, parsing->spawn[0], parsing->spawn[1]);
}

int	main(int argc, char **argv)
{
	struct s_parsing	parsing;

	if (argc < 2)
		return (0);
	if (init(&parsing, argv) != 0)
		return (1);
}
