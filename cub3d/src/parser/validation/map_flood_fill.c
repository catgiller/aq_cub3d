/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:00:00 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/04 18:00:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!copy)
		print_error("Malloc failed.");
	i = -1;
	while (++i < game->map.height)
	{
		copy[i] = ft_strdup(game->map.grid[i]);
		if (!copy[i])
		{
			free_map(copy, i);
			print_error("Malloc failed.");
		}
	}
	copy[game->map.height] = NULL;
	return (copy);
}

static void	check_neighbor(t_flood *f, int x, int y)
{
	if (x < 0 || y < 0 || x >= f->width || y >= f->height)
	{
		f->closed = 0;
		return ;
	}
	if (f->map[y][x] == '1' || f->map[y][x] == 'F')
		return ;
	if (f->map[y][x] == ' ')
	{
		f->closed = 0;
		return ;
	}
	f->map[y][x] = 'F';
	f->stack[f->top++] = y * f->width + x;
}

static void	flood_fill(t_flood *f, int start_x, int start_y)
{
	int	pos;
	int	x;
	int	y;

	f->stack = malloc(sizeof(int) * f->width * f->height);
	if (!f->stack)
		print_error("Malloc failed.");
	f->top = 0;
	f->map[start_y][start_x] = 'F';
	f->stack[f->top++] = start_y * f->width + start_x;
	while (f->top > 0)
	{
		pos = f->stack[--f->top];
		x = pos % f->width;
		y = pos / f->width;
		check_neighbor(f, x + 1, y);
		check_neighbor(f, x - 1, y);
		check_neighbor(f, x, y + 1);
		check_neighbor(f, x, y - 1);
	}
	free(f->stack);
}

void	validate_map_enclosed(t_game *game)
{
	char	**copy;
	t_flood	f;

	copy = copy_map(game);
	f.map = copy;
	f.width = game->map.width;
	f.height = game->map.height;
	f.closed = 1;
	flood_fill(&f, game->player.x, game->player.y);
	if (!f.closed)
	{
		free_map(copy, game->map.height);
		print_error("Map not enclosed by walls.");
	}
	free_map(copy, game->map.height);
}

void	validate_walkable_enclosed(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.grid[i][j] == '0'
				|| is_player_char(game->map.grid[i][j]))
			{
				if (j == 0 || j == game->map.width - 1
					|| i == 0 || i == game->map.height - 1
					|| game->map.grid[i][j - 1] == ' '
					|| game->map.grid[i][j + 1] == ' '
					|| game->map.grid[i - 1][j] == ' '
					|| game->map.grid[i + 1][j] == ' ')
					print_error("Map not enclosed by walls.");
			}
		}
	}
}
