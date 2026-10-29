/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:24:11 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/02 13:24:43 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

static void	init_tex(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->tex[i].img = NULL;
		game->tex[i].addr = NULL;
		game->tex[i].width = 0;
		game->tex[i].height = 0;
		i++;
	}
}

static void	init_structs(t_game *game)
{
	game->textures.no = NULL;
	game->textures.so = NULL;
	game->textures.we = NULL;
	game->textures.ea = NULL;
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->floor.r = 0;
	game->floor.g = 0;
	game->floor.b = 0;
	game->ceiling.r = 0;
	game->ceiling.g = 0;
	game->ceiling.b = 0;
	game->floor_set = 0;
	game->ceiling_set = 0;
	game->key_w = 0;
	game->key_s = 0;
	game->key_a = 0;
	game->key_d = 0;
	game->key_left = 0;
	game->key_right = 0;
	game->mlx.mlx = NULL;
	game->mlx.win = NULL;
	game->mlx.img.img = NULL;
	game->mlx.img.addr = NULL;
}

static void	init_player_fields(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir = '\0';
	game->player.pos_x = 0.0;
	game->player.pos_y = 0.0;
	game->player.dir_x = 0.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.0;
}

void	init_game(t_game *game)
{
	init_structs(game);
	init_player_fields(game);
	init_tex(game);
}
