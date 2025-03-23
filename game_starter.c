/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:16:33 by ayasar            #+#    #+#             */
/*   Updated: 2025/03/13 13:00:46 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_handler(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		ft_printf("Exit! Moves: %d\n", game->moves);
		ft_destroy_window(game);
		return (0);
	}
	else if ((keycode == 119 && ft_move_player(game, 0, -1) == 1)
		|| (keycode == 97 && ft_move_player(game, -1, 0) == 1)
		|| (keycode == 115 && ft_move_player(game, 0, 1) == 1)
		|| (keycode == 100 && ft_move_player(game, 1, 0) == 1))
	{
		game->moves++;
		ft_printf("Move Count: %d\n", game->moves);
	}
	return (0);
}

void	ft_find_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_size_y)
	{
		j = 0;
		while (j < game->map_size_x - 1)
		{
			if (game->map[i][j] == 'E')
			{
				game->exit.x = j;
				game->exit.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	ft_free_main(game);
	exit(0);
}

void	ft_game_starter(t_game *game)
{
	ft_find_exit(game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_free_main(game);
		ft_printf("Error: mlx_init() failed\n");
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, ((game->map_size_x) * 64),
			((game->map_size_y) * 64), "so_long");
	if (!game->win)
	{
		ft_free_main(game);
		ft_printf("Error: mlx_new_window() failed\n");
		exit(1);
	}
	game->moves = 0;
	ft_load_images(game);
	ft_map_draw(game);
	mlx_hook(game->win, 2, 1L << 0, ft_key_handler, game);
	mlx_hook(game->win, 17, 0, ft_destroy_window, game);
	mlx_loop(game->mlx);
}
