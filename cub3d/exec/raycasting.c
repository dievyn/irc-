/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letonnel <letonnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:53:42 by letonnel          #+#    #+#             */
/*   Updated: 2025/11/28 16:46:07 by letonnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

//	if spawn == W
//	1 rotation == 

void	*get_img(char *str, t_mlx *data)
{
	void	*img;
	int		width;
	int		height;

	width = 360;
	height = 360;
	img = mlx_xpm_file_to_image(data->mlx,
			str, &width, &height);
	if (!img)
		return (ft_printf(2, "Couldn't load image \"%s\".\n", str), NULL);
	return (img);
}

int	grab_img(t_parsing *parsing, t_mlx *data)
{
	data->n_img = get_img(parsing->no, data);
	if (!data->n_img)
		return (free(data->mlx), -1);
	data->s_img = get_img(parsing->so, data);
	if (!data->s_img)
		return (mlx_destroy_image(data->mlx, data->n_img), free(data->mlx), -1);
	data->e_img = get_img(parsing->ea, data);
	if (!data->e_img)
		return (mlx_destroy_image(data->mlx, data->n_img),
			mlx_destroy_image(data->mlx, data->s_img), free(data->mlx), -1);
	data->w_img = get_img(parsing->we, data);
	if (!data->w_img)
		return (mlx_destroy_image(data->mlx, data->n_img),
			mlx_destroy_image(data->mlx, data->s_img),
			mlx_destroy_image(data->mlx, data->e_img), 
			free(data->mlx), -1);
	return (0);
}

int	wall(t_parsing *parsing, int x, int y)
{
	if (x < 0 || y < 0)
		return (1);
	if (parsing->map && y >= tab_len(parsing->map))
		return (1);
	if (parsing->map && x >= ft_strlen(parsing->map[y]))
		return (1);
	if (parsing->map[y][x] == '1' || parsing->map[y][x] == 'D')
		return (1);
	return (0);
}

int	close_window(t_mlx *data)
{
	mlx_loop_end(data->mlx);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_image(data->mlx, data->n_img);
	mlx_destroy_image(data->mlx, data->s_img);
	mlx_destroy_image(data->mlx, data->e_img);
	mlx_destroy_image(data->mlx, data->w_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_parsing(data->parsing);
	exit(1);
	return (0);
}

void set_angle(t_parsing *parsing, t_mlx *m)
{
	if (parsing->spawn_dir == 'N')
		m->angle = 0;
	if (parsing->spawn_dir == 'S')
		m->angle = 78;
	if (parsing->spawn_dir == 'E')
		m->angle = 39;
	if (parsing->spawn_dir == 'W')
		m->angle = 117;
}

void exec( t_parsing *parsing )
{
	t_mlx	data;

	data.parsing = parsing;
	data.mlx = mlx_init();
	if (grab_img(parsing, &data) != 0)
		return ;
	data.win = mlx_new_window(data.mlx, SW, SH, "raycasting");
	data.line_len = 0;
	set_angle(parsing, &data);
	data.x = parsing->spawn[1] + 0.5;
	data.y = parsing->spawn[0] + 0.5;
	if (parsing->spawn_dir == 'N')
		data.a = -M_PI_2;
	if (parsing->spawn_dir == 'S')
		data.a = M_PI_2;
	if (parsing->spawn_dir == 'E')
		data.a = 0.0;
	if (parsing->spawn_dir == 'W')
		data.a = M_PI;
	data.base_a = data.a;
	data.img = mlx_new_image(data.mlx, SW, SH);
	data.px = mlx_get_data_addr(data.img, &(int){0}, &data.line_len, &(int){0});
	cast(parsing, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, KeyPress, KeyPressMask, input, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}
