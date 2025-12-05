/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letonnel <letonnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:25:38 by letonnel          #+#    #+#             */
/*   Updated: 2025/11/28 16:30:56 by letonnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	init_move_struct(t_moves *move, t_mlx *m)
{
	move->dx = cos(m->a) * MOVE_SPEED;
	move->dy = sin(m->a) * MOVE_SPEED;
	move->nx = m->x;
	move->ny = m->y;
}

static void open_doors(t_mlx *m, t_parsing *parsing, t_moves *move)
{
	if (m->facing == 'N')
	{
		if (parsing->map[(int)move->ny][(int)move->nx] == '0'
			&& parsing->map[(int)move->ny - 1][(int)move->nx] == 'D')
			parsing->map[(int)move->ny - 1][(int)move->nx] = 'x';
		else if (parsing->map[(int)move->ny][(int)move->nx] == '0'
			&& parsing->map[(int)move->ny - 1][(int)move->nx] == 'x')
			parsing->map[(int)move->ny - 1][(int)move->nx] = 'D';
	}
	else if (m->facing == 'S')
	{
		if (parsing->map[(int)move->ny][(int)move->nx] == '0'
			&& parsing->map[(int)move->ny + 1][(int)move->nx] == 'D')
			parsing->map[(int)move->ny + 1][(int)move->nx] = 'x';
		else if (parsing->map[(int)move->ny][(int)move->nx] == '0'
			&& parsing->map[(int)move->ny + 1][(int)move->nx] == 'x')
			parsing->map[(int)move->ny + 1][(int)move->nx] = 'D';
	}
	else if (m->facing == 'E')
	{
		if (parsing->map[(int)move->ny][(int)move->nx] == '0'
			&& parsing->map[(int)move->ny][(int)move->nx + 1] == 'D')
			parsing->map[(int)move->ny][(int)move->nx + 1] = 'x';
		else if (parsing->map[(int)move->ny][(int)move->nx] == '0'
			&& parsing->map[(int)move->ny][(int)move->nx + 1] == 'x')
			parsing->map[(int)move->ny][(int)move->nx + 1] = 'D';
	}
	else if (m->facing == 'W')
	{
		if (parsing->map[(int)move->ny][(int)move->nx] == '0'
			&& parsing->map[(int)move->ny][(int)move->nx - 1] == 'D')
			parsing->map[(int)move->ny][(int)move->nx - 1] = 'x';
		else if (parsing->map[(int)move->ny][(int)move->nx] == '0'
			&& parsing->map[(int)move->ny][(int)move->nx - 1] == 'x')
			parsing->map[(int)move->ny][(int)move->nx - 1] = 'D';
	}
}

static void	move_inputs(t_mlx *m, t_moves *move, int keyhook)
{
	if (keyhook == XK_a)
	{
		move->nx += move->dy;
		move->ny -= move->dx;
	}
	else if (keyhook == XK_d)
	{
		move->nx -= move->dy;
		move->ny += move->dx;
	}
	else if (keyhook == XK_w)
	{
		move->nx += move->dx;
		move->ny += move->dy;
	}
	else if (keyhook == XK_s)
	{
		move->nx -= move->dx;
		move->ny -= move->dy;
	}
	else if (keyhook == 32)
		open_doors(m, m->parsing, move);
}

static void manage_angle(t_mlx *m)
{
	if (m->angle >= 139 || m->angle <= 18)
		m->facing = 'N';
	if (m->angle >= 19 && m->angle <= 58)
		m->facing = 'E';
	if (m->angle >= 59 && m->angle <= 98)
		m->facing = 'S';
	if (m->angle >= 99 && m->angle <= 138)
		m->facing = 'W';
}

int	input(int keyhook, t_mlx *m)
{
	t_moves	move;

	init_move_struct(&move, m);
	if (keyhook == XK_Escape)
		close_window(m);
	else if (keyhook == XK_Left)
	{
		m->a -= ROT_SPEED;
		m->angle--;
		if (m->angle == -1)
			m->angle = 156;
	}
	else if (keyhook == XK_Right)
	{
		m->a += ROT_SPEED;
		m->angle++;
		if (m->angle == 157)
			m->angle = 0;
	}
	manage_angle(m);
	printf("angle: [%d]\nfacing: [%c]", m->angle, m->facing);
	move_inputs(m, &move, keyhook);
	if (!wall(m->parsing, move.nx, m->y))
		m->x = move.nx;
	if (!wall(m->parsing, m->x, move.ny))
		m->y = move.ny;
	cast(m->parsing, m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	return (0);
}
