/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:05:47 by ayasar            #+#    #+#             */
/*   Updated: 2025/03/13 13:46:30 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_size_y(int fd, t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	game->map_size_y = i;
}

void	ft_clear_gnl_buffer(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
}

char	**ft_map_copy(int fd1, int fd2, t_game *game)
{
	char	**map;
	int		i;

	ft_map_size_y(fd2, game);
	if (game->map_size_y == 0)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (game->map_size_y + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < game->map_size_y)
	{
		map[i] = get_next_line(fd1);
		if (!map[i])
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	ft_clear_gnl_buffer(fd1);
	return (map);
}
