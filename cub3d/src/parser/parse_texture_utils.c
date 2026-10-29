/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 17:38:45 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/03 16:21:25 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*skip_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line + i);
}

char	*extract_path(char *line)
{
	char	*path;
	char	*path_start;
	int		path_len;
	int		i;

	i = 0;
	line = skip_whitespace(line);
	line += 2;
	line = skip_whitespace(line);
	path_start = line;
	while (*line != '\n' && *line != '\0')
		line++;
	while (line > path_start && (*(line - 1) == ' ' || *(line - 1) == '\t'))
		line--;
	path_len = line - path_start;
	path = malloc(path_len + 1);
	if (!path)
		return (NULL);
	while (i < path_len)
	{
		path[i] = path_start[i];
		i++;
	}
	path[path_len] = '\0';
	return (path);
}

int	check_texture_file(char *path)
{
	int	i;
	int	end;
	int	fd;

	i = 0;
	while (path[i])
		i++;
	if (i < 4)
		return (0);
	end = i - 1;
	if (path[end] != 'm'
		|| path[end - 1] != 'p'
		|| path[end - 2] != 'x'
		|| path[end - 3] != '.')
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	is_empty_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == '\n' || *line == '\0')
		return (1);
	return (0);
}
