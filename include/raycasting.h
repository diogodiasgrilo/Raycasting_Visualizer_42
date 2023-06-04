/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:34:24 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/04 12:54:44 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "layout.h"
# include "game.h"
# include "check.h"
# include "errors.h"
# include "colors.h"
# include "../miniLBX/mlx.h"
# include "../libft/libft.h"

# define PI      	3.1415926535
# define DR      	0.0174533
# define RAY_ANGLE	60

typedef struct s_line_drawing
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}				t_line_drawing;

typedef struct s_image_creator
{
	int		x;
	int		y;
	char	*data;
	void	*img;
	int		pix_index;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image_creator;

void		draw_rays(t_game *g);
void		print_moves(t_game g);
int			ft_input(int key, void *param);
int			ft_input(int key, void *param);
void		handle_angles(t_game *g, int key);
void		handle_directions(t_game *g, int one_dif);
void		draw_line(t_game *g, float pdx, float pdy);
void		*create_image(void *mlx, t_lay lay, char **map);
void		create_rows(t_image_creator *ic, t_lay lay, char **map);

#endif