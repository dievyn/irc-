/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letonnel <letonnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:32:42 by letonnel          #+#    #+#             */
/*   Updated: 2025/11/28 16:34:51 by letonnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	point(t_mlx *m, int x, int y, int c)
{
	if (x >= 0 && x < SW && y >= 0 && y < SH)
		*(int *)(m->px + y * m->line_len + x * 4) = c;
}

static void	strip(t_mlx *m, int col, int h, int side)
{
	int	y;
	int	top;
	int	bot;
	int	c;

	y = 0;
	top = (SH - h) / 2;
	bot = top + h;
	if (side == 1)
		c = 0x606060;
	else if (side == 2)
		c = 0xCCCCCC;
	else if (side == 3)
		c = 0xcdeb34;
	else if (side == 4)
		c = 0xeb8f34;
	while (y < top)
		point(m, col, y++, m->parsing->cieling);
	while (y < bot)
		point(m, col, y++, c);
	while (y < SH)
		point(m, col, y++, m->parsing->floor);
	// if (col % 3 != 0 && col % 2 != 0)
	// {
	// 	point(m, col, SH / 2, 0xf54242);
	// 	point(m, col, SH / 2 + 1, 0xf54242);
	// 	point(m, col, SH / 2 + 2, 0xf54242);
	// }
}

// 1 = gris
// 2 = blanc
// 3 = vert	[sud]
// 4 = orange

static int	detect_side(t_mlx *m, t_ray *r, int side)
{
	printf("%f", m->move->ny);
	if (side == 1)
	{
		if (r->my + 1 > tab_len(m->parsing->map))
			return (3);
		if (r->my - 1 < 0)
			return (1);
		if (m->move->ny >= r->my)
			return (1);
		if (m->move->ny <= r->my)
			return (3);
		return (0);
	}
	else
	{
		if (r->mx + 1 > ft_strlen(m->parsing->map[r->my]))
			return (4);
		if (r->mx - 1 < 0)
			return (2);
		if (m->move->nx >= r->mx)
			return (2);
		if (m->move->nx <= r->mx)
			return (4);
		return (0);
		// if (lround(r->mx + 1) >= ft_strlen(m->parsing->map[r->my]))
		// 	return (2);
		// if (m->parsing->map[r->my][r->mx + 1] && m->parsing->map[r->my][r->mx + 1] == '0')
		// 	return (4);
		// return (2);
	}
}

static double	trace(t_mlx *move, t_ray *r)
{
	int		hit;

	hit = 0;
	while (!hit)
	{
		if (r->sdx < r->sdy)
		{
			r->sdx += r->ddx;
			r->mx += r->stx;
			r->side = 0;
		}
		else
		{
			r->sdy += r->ddy;
			r->my += r->sty;
			r->side = 1;
		}
		hit = wall(move->parsing, r->mx, r->my);
	}
	r->side = detect_side(move, r, r->side);
	if (r->side == 0)
		exit(0);
	if (r->side == 2 || r->side == 4)
		r->sdx -= r->ddx;
	else if (r->side == 1 || r->side == 3)
		r->sdy -= r->ddy;
	if (r->side == 2 || r->side == 4)
		return (r->sdx);
	else if (r->side == 1 || r->side == 3)
		return (r->sdy);
	return (0);
}

void	cast(t_mlx *m)
{
	int			col;
	t_ray		r;
	double		ra;
	double		d;
	int			h;

	col = 0;
	ft_bzero(m->px, SW * SH * 4);
	while (col < SW)
	{
		ra = m->a + FOV * (col / (double)SW - 0.5);
		setup_dda(m, ra, &r);
		d = trace(m, &r);
		h = (int)(SH * 2 / (d * 1.75));
		if (h < 2)
			h = 2;
		if (h > SH)
			h = SH;
		strip(m, col, h, r.side);
		col++;
	}
}
