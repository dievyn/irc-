/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letonnel <letonnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:38:06 by letonnel          #+#    #+#             */
/*   Updated: 2025/11/28 16:39:22 by letonnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	finish_setup(t_mlx *m, t_ray *r, double dx, double dy)
{
	if (dx < 0)
	{
		r->stx = -1;
		r->sdx = (m->x - r->mx) * r->ddx;
	}
	else
	{
		r->stx = 1;
		r->sdx = (r->mx + 1 - m->x) * r->ddx;
	}
	if (dy < 0)
	{
		r->sty = -1;
		r->sdy = (m->y - r->my) * r->ddy;
	}
	else
	{
		r->sty = 1;
		r->sdy = (r->my + 1 - m->y) * r->ddy;
	}
}

void	setup_dda(t_mlx *m, double ra, t_ray *r)
{
	double		dx;
	double		dy;

	dx = cos(ra);
	dy = sin(ra);
	r->ddx = fabs(1 / dx);
	r->ddy = fabs(1 / dy);
	r->mx = (int)m->x;
	r->my = (int)m->y;
	finish_setup(m, r, dx, dy);
}
