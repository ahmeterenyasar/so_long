/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_comp_loc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:24:30 by ayasar            #+#    #+#             */
/*   Updated: 2025/03/05 12:26:17 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_locate_player(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_size_y - 1)
	{
		j = 0;
		while (j < game->map_size_x)
		{
			if (map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_locate_exit(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_size_y)
	{
		j = 0;
		while (j < game->map_size_x)
		{
			if (map[i][j] == 'E')
			{
				game->exit.x = j;
				game->exit.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_locate_collectables(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_size_y - 1 > i)
	{
		j = 0;
		while (game->map_size_x > j)
		{
			if (map[i][j] == 'C')
			{
				game->collect.x = j;
				game->collect.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
