/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:15:00 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/07 19:15:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_one_texture(t_game *game, int id, char *path)
{
	game->tex[id].img = mlx_xpm_file_to_image(game->mlx.mlx, path,
			&game->tex[id].width, &game->tex[id].height);
	if (!game->tex[id].img)
		print_error("Failed to load texture!");
	game->tex[id].addr = mlx_get_data_addr(game->tex[id].img,
			&game->tex[id].bpp, &game->tex[id].line_len,
			&game->tex[id].endian);
}

void	load_textures(t_game *game)
{
	load_one_texture(game, TEX_NO, game->textures.no);
	load_one_texture(game, TEX_SO, game->textures.so);
	load_one_texture(game, TEX_WE, game->textures.we);
	load_one_texture(game, TEX_EA, game->textures.ea);
}
