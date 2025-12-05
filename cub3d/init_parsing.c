/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	**add_new(char **tab, char *new_str)
{
	char	**copy;
	int		i;

	i = 0;
	copy = ft_calloc(tab_len(tab) + 2, sizeof(char **));
	while (tab[i])
	{
		copy[i] = ft_strdup(tab[i]);
		i++;
	}
	copy[i] = ft_strdup(new_str);
	free(new_str);
	free_tab(tab);
	return (copy);
}

static void	set_null(t_parsing *parsing)
{
	parsing->no = NULL;
	parsing->so = NULL;
	parsing->ea = NULL;
	parsing->we = NULL;
	parsing->map = NULL;
}

static char	**init_parsing(t_parsing *parsing, char **argv)
{
	char	*tmp;
	int		fd;
	char	**tab;

	set_null(parsing);
	tmp = ft_substr(argv[1], ft_strlen(argv[1]) - 4, ft_strlen(argv[1]));
	if (!tmp || ft_strncmp(tmp, ".cub", 4) != 0)
		return (free(tmp), ft_printf(2, "Error\nWrong map name. "
				"Must be \".cub\" file.\n"), NULL);
	free(tmp);
	parsing->map_name = ft_strdup(argv[1]);
	fd = open(parsing->map_name, O_RDONLY);
	if (fd == -1)
		return (ft_printf(2, "Error\nNo such file or directory: %s.\n",
				parsing->map_name), NULL);
	tab = ft_calloc (1, sizeof (char **));
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp)
			tab = add_new(tab, tmp);
		else
			return (close (fd), tab);
	}
}

int	init(t_parsing *parsing, char **argv)
{
	char	**tab;

	tab = init_parsing(parsing, argv);
	if (tab == NULL)
		return (free_parsing(parsing), -1);
	if (parsing_errors(tab) != 0 || grab_info(tab, parsing) != 0)
		return (free_tab(tab), free_parsing(parsing), -1);
	print_infos(parsing);
	free_tab(tab);
	exec(parsing);
	free_parsing(parsing);
	return (0);
}
