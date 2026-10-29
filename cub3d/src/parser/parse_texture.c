/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:46:26 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/06 15:12:46 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>

int	get_identifier(char *line)
{
	if (!ft_strncmp(line, "NO", 2)
		&& (line[2] == ' ' || line[2] == '\t'))
		return (NO_ID);
	else if (!ft_strncmp(line, "SO", 2)
		&& (line[2] == ' ' || line[2] == '\t'))
		return (SO_ID);
	else if (!ft_strncmp(line, "WE", 2)
		&& (line[2] == ' ' || line[2] == '\t'))
		return (WE_ID);
	else if (!ft_strncmp(line, "EA", 2)
		&& (line[2] == ' ' || line[2] == '\t'))
		return (EA_ID);
	return (0);
}

void	store_texture(t_game *game, int id, char *path)
{
	if (id == NO_ID && game->textures.no == NULL)
		game->textures.no = path;
	else if (id == SO_ID && game->textures.so == NULL)
		game->textures.so = path;
	else if (id == WE_ID && game->textures.we == NULL)
		game->textures.we = path;
	else if (id == EA_ID && game->textures.ea == NULL)
		game->textures.ea = path;
	else
	{
		free(path);
		print_error("Invalid texture configuration.");
	}
}

void	parse_texture(char *line, t_game *game)
{
	int		id;
	char	*path;

	line = skip_whitespace(line);
	id = get_identifier(line);
	if (id == 0)
		print_error("Invalid texture identifier.");
	path = extract_path(line);
	if (!path)
		print_error("Malloc failed.");
	if (!check_texture_file(path))
	{
		free(path);
		print_error("Invalid texture file.");
	}
	store_texture(game, id, path);
}
