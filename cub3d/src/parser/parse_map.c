/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:25:50 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/04 18:00:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	check_config_complete(t_game *game)
{
	if (!game->textures.no || !game->textures.so
		|| !game->textures.we || !game->textures.ea)
		print_error("Missing texture.");
	if (!game->floor_set)
		print_error("Missing floor color.");
	if (!game->ceiling_set)
		print_error("Missing ceiling color.");
}

static int	is_config_line(char *line)
{
	line = skip_whitespace(line);
	if (!ft_strncmp(line, "NO", 2)
		&& (line[2] == ' ' || line[2] == '\t'))
		return (1);
	if (!ft_strncmp(line, "SO", 2)
		&& (line[2] == ' ' || line[2] == '\t'))
		return (1);
	if (!ft_strncmp(line, "WE", 2)
		&& (line[2] == ' ' || line[2] == '\t'))
		return (1);
	if (!ft_strncmp(line, "EA", 2)
		&& (line[2] == ' ' || line[2] == '\t'))
		return (1);
	if (!ft_strncmp(line, "F", 1)
		&& (line[1] == ' ' || line[1] == '\t'))
		return (1);
	if (!ft_strncmp(line, "C", 1)
		&& (line[1] == ' ' || line[1] == '\t'))
		return (1);
	return (0);
}

static int	check_map_content(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (is_config_line(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_map(t_game *game, char *first_map_line, int fd)
{
	char	**map;
	int		height;
	int		width;

	check_config_complete(game);
	map = read_map_lines(first_map_line, fd, &height);
	set_line(NULL);
	if (!map)
		print_error("Failed to read map.");
	if (!check_map_content(map))
	{
		free_map(map, height);
		print_error("Config line in map.");
	}
	width = calculate_map_width(map);
	if (!store_map(game, map, width, height))
	{
		free_map(map, height);
		print_error("Failed to store map.");
	}
	free_map(map, height);
	parse_map_validation(game);
	return (1);
}
