/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:03:46 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/04 12:57:12 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "raycasting.h"

# define SIZE 32

/* Main attributes for the game */
typedef struct s_game
{
	int			width;
	int			height;
	int			px;
	int			py;
	float		pdx;
	float		pdy;
	float		pa;
	void		*id;
	void		*w_id;
	void		*player;
	void		*img;
	t_lay		*lay;
	t_lay		lay_bak;
	char		**map;
	
}				t_game;

int				free_map_exit(void *game);
void			start_game(char **map, t_lay lay);
void			ft_newgame(t_game *g, char **m, t_lay *lay);

#endif