/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 00:18:23 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/03 16:20:25 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include <stdlib.h>

void	read_file(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		print_error("Empty file.");
	while (line)
	{
		set_line(line);
		if (get_identifier(skip_whitespace(line)) != 0)
			parse_texture(line, game);
		else if (get_color_identifier(skip_whitespace(line)) != 0)
			parse_color(line, game);
		else if (!is_empty_line(line))
		{
			parse_map(game, line, fd);
			return ;
		}
		free(line);
		set_line(NULL);
		line = get_next_line(fd);
	}
	print_error("No map found.");
}
