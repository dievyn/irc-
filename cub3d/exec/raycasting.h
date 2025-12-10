/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letonnel <letonnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:54:14 by letonnel          #+#    #+#             */
/*   Updated: 2025/11/28 16:36:11 by letonnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdint.h>
# include "../cube.h"
# include <stdio.h>
# include "mlx/mlx_int.h"
# include "mlx/mlx.h"

// # define FOV (60 * M_PI / 180)
# define FOV 1.05
# define SW 640
# define SH 480
# define ROT_SPEED 0.04
# define MOVE_SPEED 0.05

typedef struct s_parsing
t_parsing;

typedef struct s_moves
{
	double	nx;
	double	ny;
	double	dx;
	double	dy;
}	t_moves;

typedef struct s_ray
{
	double	ddx;
	double	ddy;
	double	sdx;
	double	sdy;
	int		mx;
	int		my;
	int		stx;
	int		sty;
	int		side;
}	t_ray;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*px;
	double	x;
	double	y;
	double	a;
	int		line_len;
	void	*n_img;
	void	*s_img;
	void	*e_img;
	void	*w_img;
	t_parsing	*parsing;
	t_moves		*move;
	double	base_a;
	int		angle;
	char	facing;
}	t_mlx;

int		close_window(t_mlx *data);
int		input(int keyhook, t_mlx *m);
void	exec( t_parsing *parsing );
int		wall(t_parsing *parsing, int x, int y);
void	cast(t_mlx *m);
void	setup_dda(t_mlx *m, double ra, t_ray *r);
void	init_move_struct(t_moves *move, t_mlx *m);

#endif
