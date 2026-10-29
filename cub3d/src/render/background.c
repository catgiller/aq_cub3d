/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:05:00 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/07 19:05:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	encode_rgb(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;
	int	c_color;
	int	f_color;

	c_color = encode_rgb(game->ceiling);
	f_color = encode_rgb(game->floor);
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
			my_mlx_pixel_put(&game->mlx.img, x++, y, c_color);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
			my_mlx_pixel_put(&game->mlx.img, x++, y, f_color);
		y++;
	}
}
