/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:33:42 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/04 13:35:38 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	put_on_screen(t_game *g, t_line_drawing *rs)
{
	while (1)
	{
		mlx_pixel_put(g->id, g->w_id, rs->x1, rs->y1, NEWWHITE);
		if ((rs->x1 == rs->x2 && rs->y1 == rs->y2) || \
			g->map[rs->y1 / SIZE][rs->x1 / SIZE] == '1')
			break ;
		rs->e2 = 2 * rs->err;
		if (rs->e2 >= rs->dy)
		{
			rs->err += rs->dy;
			rs->x1 += rs->sx;
		}
		if (rs->e2 <= rs->dx)
		{
			rs->err += rs->dx;
			rs->y1 += rs->sy;
		}
	}
}

void	draw_line(t_game *g, float pdx, float pdy)
{
	t_line_drawing	rs;

	rs.x1 = (g->px * SIZE) + 15;
	rs.y1 = (g->py * SIZE) + 15;
	rs.x2 = ((g->px + pdx) * SIZE) + 15;
	rs.y2 = ((g->py + pdy) * SIZE) + 15;
	rs.dx = abs((rs.x2 - rs.x1));
	rs.dy = -abs((rs.y2 - rs.y1));
	rs.err = rs.dx + rs.dy;
	if (rs.x1 < rs.x2)
		rs.sx = 1;
	else
		rs.sx = -1;
	if (rs.y1 < rs.y2)
		rs.sy = 1;
	else
		rs.sy = -1;
	put_on_screen(g, &rs);
}

void	draw_rays(t_game *g)
{
	int		i;
	float	ray_angle;
	float	pdx;
	float	pdy;

	i = -1;
	ray_angle = g->pa - (DR * 30);
	while (++i < RAY_ANGLE)
	{
		pdx = cos(ray_angle) * SIZE;
		pdy = sin(ray_angle) * SIZE;
		draw_line(g, pdx, pdy);
		ray_angle += DR / 2;
		pdx = cos(ray_angle) * SIZE;
		pdy = sin(ray_angle) * SIZE;
		draw_line(g, pdx, pdy);
		ray_angle += DR / 2;
	}
	mlx_put_image_to_window(g->id, g->w_id, g->player, \
		g->px * SIZE + 10, g->py * SIZE + 10);
}

void	create_rows(t_image_creator *ic, t_lay lay, char **map)
{
	while (ic->x < lay.n_col * SIZE)
	{
		ic->pix_index = (ic->x * ic->bpp / 8) + (ic->y * ic->size_line);
		if (map[ic->y / SIZE][ic->x / SIZE] == '1')
			*(unsigned int *)(ic->data + ic->pix_index) = GREY;
		else if (map[ic->y / SIZE][ic->x / SIZE] == '0' || \
			map[ic->y / SIZE][ic->x / SIZE] == 'C')
			*(unsigned int *)(ic->data + ic->pix_index) = BLACK;
		ic->x++;
	}
}

void	*create_image(void *mlx, t_lay lay, char **map)
{
	t_image_creator	ic;

	ic.y = 0;
	ic.img = mlx_new_image(mlx, lay.n_col * SIZE, lay.n_row * SIZE);
	ic.data = mlx_get_data_addr(ic.img, &ic.bpp, &ic.size_line, &ic.endian);
	while (ic.y < lay.n_row * SIZE)
	{
		ic.x = 0;
		create_rows(&ic, lay, map);
		ic.y++;
	}
	return (ic.img);
}
