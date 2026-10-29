/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:15:00 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/07 19:15:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dir_north_south(t_player *p)
{
	if (p->dir == 'N')
	{
		p->dir_x = 0.0;
		p->dir_y = -1.0;
		p->plane_x = 0.66;
		p->plane_y = 0.0;
	}
	else if (p->dir == 'S')
	{
		p->dir_x = 0.0;
		p->dir_y = 1.0;
		p->plane_x = -0.66;
		p->plane_y = 0.0;
	}
}

static void	set_dir_east_west(t_player *p)
{
	if (p->dir == 'E')
	{
		p->dir_x = 1.0;
		p->dir_y = 0.0;
		p->plane_x = 0.0;
		p->plane_y = 0.66;
	}
	else if (p->dir == 'W')
	{
		p->dir_x = -1.0;
		p->dir_y = 0.0;
		p->plane_x = 0.0;
		p->plane_y = -0.66;
	}
}

void	init_player(t_game *game)
{
	game->player.pos_x = (double)game->player.x + 0.5;
	game->player.pos_y = (double)game->player.y + 0.5;
	set_dir_north_south(&game->player);
	set_dir_east_west(&game->player);
}
