/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:50:09 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/27 11:50:22 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "big_ft/libft.h"
# include "exec/raycasting.h"

typedef struct s_parsing
{
	char	*map_name;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	**map;
	int		floor;
	int		cieling;
	int		spawn[2];
	char	spawn_dir;
}	t_parsing;

//	checks_parsing -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

int				parsing_errors(char **map);
int				detect_empty(char *str);
int				check_dups(char **map);
int				detect_map(char *str);
int				check_below_map(char **map);
int				unknown_char(char **map);
int				check_textures(char **map);
int				check_colors(char **map);

//	grab_info -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

unsigned int	decrypt_colors(int *tab);
char			*bitstring(unsigned char num);
int				grab_info(char **map, t_parsing *parsing);
int				grab_textures(char **map, t_parsing *parsing);
int				grab_colors(char **map, t_parsing *parsing);
void			grab_spawn(char **map, t_parsing *parsing);
int				check_spawn(char **map);
int				fill_me_up(char **map, int i, int j);
char			**get_map(t_parsing *parsing, char **tab);
int				is_what_str(char c, char *exceptions);

//	random -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void			print_infos(t_parsing *parsing);
int				free_parsing(t_parsing *parsing);
int				init(t_parsing *parsing, char **argv);

#endif
