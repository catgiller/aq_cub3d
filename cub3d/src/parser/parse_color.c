/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 10:13:17 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/03 14:22:36 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	read_number(char **line, int *value)
{
	if (!ft_isdigit(**line))
		return (0);
	*value = ft_atoi(*line);
	if (*value < 0 || *value > 255)
		return (0);
	while (ft_isdigit(**line))
		(*line)++;
	return (1);
}

int	extract_rgb(char *line, t_color *color)
{
	line = skip_whitespace(line);
	line++;
	line = skip_whitespace(line);
	if (!read_number(&line, &color->r))
		return (0);
	if (*line != ',')
		return (0);
	line = skip_whitespace(line + 1);
	if (!read_number(&line, &color->g))
		return (0);
	if (*line != ',')
		return (0);
	line = skip_whitespace(line + 1);
	if (!read_number(&line, &color->b))
		return (0);
	line = skip_whitespace(line);
	if (*line != '\0' && *line != '\n')
		return (0);
	return (1);
}

int	get_color_identifier(char *line)
{
	if (!ft_strncmp(line, "F", 1)
		&& (line[1] == ' ' || line[1] == '\t'))
		return (FLOOR_ID);
	else if (!ft_strncmp(line, "C", 1)
		&& (line[1] == ' ' || line[1] == '\t'))
		return (CEILING_ID);
	return (0);
}

void	store_color(t_game *game, int id, t_color color)
{
	if (id == FLOOR_ID && game->floor_set == 0)
	{
		game->floor = color;
		game->floor_set = 1;
	}
	else if (id == CEILING_ID && game->ceiling_set == 0)
	{
		game->ceiling = color;
		game->ceiling_set = 1;
	}
	else
		print_error("Invalid color configuration.");
}

void	parse_color(char *line, t_game *game)
{
	int		id;
	t_color	color;

	if (!game->textures.no || !game->textures.so
		|| !game->textures.we || !game->textures.ea)
		print_error("Textures must come before colors.");
	line = skip_whitespace(line);
	id = get_color_identifier(line);
	if (id == 0)
		print_error("Invalid color identifier.");
	if (!extract_rgb(line, &color))
		print_error("Invalid color format.");
	store_color(game, id, color);
}
