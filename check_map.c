/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:22:20 by ayasar            #+#    #+#             */
/*   Updated: 2025/03/12 17:06:06 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_validate_map(char **map, t_game *game)
{
	ft_check_rectangle(map, game);
	ft_check_characters(map, game);
	ft_check_wall(map, game);
	ft_check_components(map, game);
	ft_check_valid_path(map, game);
}

void	ft_open_map_files(t_game *game, char *filename, int *fd1, int *fd2)
{
	*fd1 = open(filename, O_RDONLY);
	*fd2 = open(filename, O_RDONLY);
	if (*fd1 == -1 || *fd2 == -1)
	{
		if (*fd1 != -1)
			close(*fd1);
		if (*fd2 != -1)
			close(*fd2);
		ft_handle_map_error(game, NULL, "Error: Cannot open map file\n");
		exit(1);
	}
}

void	ft_check_map(t_game *game, char *filename)
{
	int		fd1;
	int		fd2;
	char	**map;

	ft_open_map_files(game, filename, &fd1, &fd2);
	map = ft_map_copy(fd1, fd2, game);
	if (map == NULL)
	{
		close(fd1);
		close(fd2);
		ft_handle_map_error(game, map, "Error: Empty or invalid map\n");
		exit(1);
	}
	ft_validate_map(map, game);
	ft_free_map(map);
	close(fd1);
	close(fd2);
}
