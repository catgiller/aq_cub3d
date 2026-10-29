/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:00:00 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/04 18:00:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_UTILS_H
# define PARSE_MAP_UTILS_H

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}	t_node;

void	trim_newline(char *line);
t_node	*node_new(char *str);
void	node_add_back(t_node **head, t_node *new_node);
void	free_node_list(t_node *head);

#endif
