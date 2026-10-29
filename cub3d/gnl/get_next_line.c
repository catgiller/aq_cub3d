/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 00:00:00 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/04 18:00:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*g_stash;

static char	*join_and_free(char *s1, char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	joined = malloc(len1 + len2 + 1);
	if (!joined)
	{
		free(s1);
		return (NULL);
	}
	if (s1)
		ft_memcpy(joined, s1, len1);
	if (s2)
		ft_memcpy(joined + len1, s2, len2);
	joined[len1 + len2] = '\0';
	free(s1);
	return (joined);
}

static char	*extract_line(char **stash)
{
	char	*line;
	char	*nl;
	size_t	len;
	char	*new_stash;

	nl = ft_strchr(*stash, '\n');
	if (nl)
	{
		len = nl - *stash + 1;
		line = malloc(len + 1);
		if (!line)
			return (NULL);
		ft_memcpy(line, *stash, len);
		line[len] = '\0';
		new_stash = ft_strdup(nl + 1);
		free(*stash);
		*stash = new_stash;
		return (line);
	}
	line = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}

static int	read_to_stash(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	n;

	n = 1;
	while (n && (!*stash || !ft_strchr(*stash, '\n')))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (free(*stash), *stash = NULL, 0);
		buffer[n] = '\0';
		*stash = join_and_free(*stash, buffer);
		if (!*stash)
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_to_stash(fd, &g_stash))
		return (NULL);
	if (!g_stash || !g_stash[0])
	{
		free(g_stash);
		g_stash = NULL;
		return (NULL);
	}
	return (extract_line(&g_stash));
}

void	free_gnl_stash(void)
{
	free(g_stash);
	g_stash = NULL;
}
