/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:37:30 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/02 00:18:35 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	check_file_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	while (len > 0 && file_name[len - 1] != '/')
		len--;
	len = ft_strlen(file_name) - len;
	if (len < 5)
		return (0);
	if (ft_strncmp(&file_name[ft_strlen(file_name) - 4], ".cub", 4) != 0)
		return (0);
	return (1);
}

void	parser(t_game *game, char *file)
{
	int	fd;

	if (!check_file_extension(file))
		print_error("Invalid file extension.");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Opening file failed.");
	read_file(fd, game);
	close(fd);
}
