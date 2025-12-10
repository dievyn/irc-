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

void	init_move_struct(t_moves *move, t_mlx *m)
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

int check_walls(t_mlx *m, int direction)
{
	if (direction == 0 && (m->parsing->map[]m->y < 
		|| m->parsing->map[lround(m->move->ny - 0.4)][lround(m->x)] == 'D'))
		return (1);
	return (0);
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
	else if (keyhook == XK_w && check_walls(m, 0) == 0)
	{
		move->nx += move->dx;
		move->ny += move->dy;
	}
	else if (keyhook == XK_s)
	{
		move->nx -= move->dx;
		move->ny -= move->dy;
	}
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

/*
	N --------------
	n - 0
	e - 39
	s - 79
	w - 118

	S --------------
	n - 1
	e - 40
	s - 79
	w - 118

	E --------------
	n - 0
	e - 39
	s - 78
	w - 118

	W --------------
	n - 0
	e - 40
	s - 79
	w - 118
*/

int	input(int keyhook, t_mlx *m)
{
	init_move_struct(m->move, m);
	if (keyhook == XK_Escape)
		close_window(m);
	else if (keyhook == XK_Left)
	{
		m->a -= ROT_SPEED;
		m->angle--;
		if (m->angle <= -1)
			m->angle = 156;
	}
	else if (keyhook == XK_Right)
	{
		m->a += ROT_SPEED;
		m->angle++;
		if (m->angle >= 157)
			m->angle = 0;
	}
	else if (keyhook == 32)
		open_doors(m, m->parsing, m->move);	
	manage_angle(m);
	move_inputs(m, m->move, keyhook);
	if (!wall(m->parsing, m->move->nx, m->y))
		m->x = m->move->nx;
	if (!wall(m->parsing, m->x, m->move->ny))
		m->y = m->move->ny;
	cast(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	return (0);
}
