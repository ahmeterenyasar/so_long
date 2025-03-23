/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:55:24 by ayasar            #+#    #+#             */
/*   Updated: 2025/03/12 17:00:56 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_is_all_collected(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_size_y)
	{
		j = 0;
		while (j < game->map_size_x)
		{
			if (game->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_destroy_map(t_game *game)
{
	int	i;

	if (!game->map)
		return (0);
	i = 0;
	while (i < game->map_size_y && game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
	return (1);
}

int	ft_destroy_mlx(t_game *game)
{
	if (game->mlx)
	{
		if (game->img_collect)
			mlx_destroy_image(game->mlx, game->img_collect);
		if (game->img_floor)
			mlx_destroy_image(game->mlx, game->img_floor);
		if (game->img_exit)
			mlx_destroy_image(game->mlx, game->img_exit);
		if (game->img_player)
			mlx_destroy_image(game->mlx, game->img_player);
		if (game->img_wall)
			mlx_destroy_image(game->mlx, game->img_wall);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	return (1);
}

int	ft_destroy_window(t_game *game)
{
	if (!game)
		return (0);
	ft_destroy_map(game);
	ft_destroy_mlx(game);
	free(game);
	exit(0);
	return (1);
}
