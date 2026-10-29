/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 23:57:45 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/01 01:13:49 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

static t_game	*g_game;
static char		*g_line;

void	set_game(t_game *game)
{
	g_game = game;
}

void	set_line(char *line)
{
	g_line = line;
}

void	print_error(char *message)
{
	if (g_line)
		free(g_line);
	free_gnl_stash();
	if (g_game)
		free_game(g_game);
	printf("Error: %s\n", message);
	exit(1);
}
