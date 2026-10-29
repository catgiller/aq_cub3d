/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:34:23 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/04 18:00:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1'
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	validate_map_chars(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (!is_valid_map_char(game->map.grid[i][j]))
				print_error("Invalid character in map.");
			if (is_player_char(game->map.grid[i][j]))
			{
				if (game->player.dir)
					print_error("Multiple player spawns.");
				game->player.x = j;
				game->player.y = i;
				game->player.dir = game->map.grid[i][j];
			}
		}
	}
	if (!game->player.dir)
		print_error("No player spawn.");
}

static void	validate_empty_lines(t_game *game)
{
	int	i;
	int	j;
	int	has;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		has = 0;
		while (++j < game->map.width)
		{
			if (game->map.grid[i][j] != ' ')
			{
				has = 1;
				break ;
			}
		}
		if (!has)
			print_error("Empty line in map.");
	}
}

void	parse_map_validation(t_game *game)
{
	validate_map_chars(game);
	validate_empty_lines(game);
	validate_map_enclosed(game);
	validate_walkable_enclosed(game);
}
