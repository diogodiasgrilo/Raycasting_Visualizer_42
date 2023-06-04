/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:09:21 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/04 12:50:45 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	start_game(char **map, t_lay lay)
{
	int		size;
	t_game	g;

	size = SIZE;
	g.lay_bak = lay;
	g.id = mlx_init();
	g.w_id = mlx_new_window(g.id, lay.n_col * SIZE, lay.n_row * SIZE,
			"Cub3d");
	g.img = create_image(g.id, lay, map);
	mlx_put_image_to_window(g.id, g.w_id, g.img, 0, 0);
	g.player = mlx_xpm_file_to_image(g.id, \
		"./sprites/square.xpm", &size, &size);
	ft_newgame(&g, map, &lay);
	find_player(&g, map);
	g.pdx = (cos(g.pa) * SIZE);
	g.pdy = (sin(g.pa) * SIZE);
	draw_rays(&g);
	mlx_hook(g.w_id, 17, 0, free_map_exit, &g);
	mlx_key_hook(g.w_id, *ft_input, &g);
	mlx_loop(g.id);
}

void	ft_newgame(t_game *g, char **m, t_lay *lay)
{
	g->width = lay->n_col * SIZE;
	g->height = lay->n_row * SIZE;
	g->lay = lay;
	g->map = m;
	g->pa = PI * 2;
}

void	find_player(t_game *g, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				g->px = j;
				g->py = i;
				return ;
			}
		}
	}
}
