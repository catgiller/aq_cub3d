/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
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

static void	fill_row(char *dst, char *src, int width)
{
	ft_memset(dst, ' ', width);
	ft_memcpy(dst, src, ft_strlen(src));
	dst[width] = '\0';
}

int	store_map(t_game *game, char **map, int width, int height)
{
	char	**grid;
	int		i;

	grid = malloc(sizeof(char *) * height);
	if (!grid)
		return (0);
	i = 0;
	while (i < height)
	{
		grid[i] = malloc(width + 1);
		if (!grid[i])
		{
			free_map(grid, i);
			return (0);
		}
		fill_row(grid[i], map[i], width);
		i++;
	}
	game->map.grid = grid;
	game->map.width = width;
	game->map.height = height;
	return (1);
}
