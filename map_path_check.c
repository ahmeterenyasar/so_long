/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:47:34 by ayasar            #+#    #+#             */
/*   Updated: 2025/03/13 11:26:55 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **map, int player_x, int player_y, t_game *game)
{
	if (player_x < 0 || player_x >= game->map_size_x || player_y < 0
		|| player_y >= game->map_size_y || map[player_y][player_x] == '1'
		|| map[player_y][player_x] == 'Y')
	{
		return ;
	}
	if (map[player_y][player_x] == 'E')
	{
		map[player_y][player_x] = 'Y';
		return ;
	}
	map[player_y][player_x] = 'Y';
	ft_flood_fill(map, player_x + 1, player_y, game);
	ft_flood_fill(map, player_x - 1, player_y, game);
	ft_flood_fill(map, player_x, player_y + 1, game);
	ft_flood_fill(map, player_x, player_y - 1, game);
}

void	ft_map_copy_for_path(char **map, t_game *game)
{
	int	i;

	game->map = (char **)malloc(sizeof(char *) * (game->map_size_y + 1));
	if (!game->map)
		ft_handle_map_error(game, map, "Error: Malloc fail!\n");
	i = -1;
	while (map[++i])
	{
		game->map[i] = ft_strdup(map[i]);
		if (!game->map[i])
			ft_handle_map_error(game, game->map, "Error: Malloc fail!\n");
	}
	game->map[i] = NULL;
}

void	ft_check_valid_path(char **map, t_game *game)
{
	int	original_size_y;

	ft_map_copy_for_path(map, game);
	ft_locate_player(game, map);
	ft_flood_fill(map, game->player.x, game->player.y, game);
	ft_locate_exit(game, map);
	ft_locate_collectables(game, map);
	if (game->collect.x != 0 || game->collect.y != 0 || game->exit.x != 0
		|| game->exit.y != 0)
	{
		original_size_y = game->map_size_y;
		while (original_size_y--)
			free(game->map[original_size_y]);
		free(game->map);
		game->map = NULL;
		ft_handle_map_error(game, map,
			"Error: No path to exit or collectible\n");
	}
}
