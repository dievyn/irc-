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

// 1 = gris
// 2 = blanc
// 3 = vert
// 4 = orange

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
}

static int	detect_side(double x, double y, int side)
{
	if (side == 1)
	{
		if (lround(y) == (long)(y))
			return (1);
		else
			return (3);
	}
	else
	{
		if (lround(x) == (long)(x))
			return (4);
		else
			return (2);
	}
	return (-1);
}

static double	trace(t_parsing *parsing, t_ray *r)
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
		hit = wall(parsing, r->mx, r->my);
	}
	r->side = detect_side(r->sdx, r->sdy, r->side);
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

void	cast(t_parsing *parsing, t_mlx *m)
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
		d = trace(parsing, &r);
		h = (int)(SH * 2 / (d * 1.75));
		if (h < 2)
			h = 2;
		if (h > SH)
			h = SH;
		strip(m, col, h, r.side);
		col++;
	}
}
