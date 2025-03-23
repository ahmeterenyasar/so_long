/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:15:42 by ayasar            #+#    #+#             */
/*   Updated: 2025/03/13 11:04:56 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&img_width, &img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm",
			&img_width, &img_height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "./textures/coin.xpm",
			&img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&img_width, &img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&img_width, &img_height);
}

void	ft_map_draw(t_game *game)
{
	game->map_coord.y = -1;
	while (++game->map_coord.y < game->map_size_y)
	{
		game->map_coord.x = -1;
		while (++game->map_coord.x < game->map_size_x)
		{
			if (game->map[game->map_coord.y][game->map_coord.x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
					game->map_coord.x * 64, game->map_coord.y * 64);
			else if (game->map[game->map_coord.y][game->map_coord.x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,
					game->map_coord.x * 64, game->map_coord.y * 64);
			else if (game->map[game->map_coord.y][game->map_coord.x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collect,
					game->map_coord.x * 64, game->map_coord.y * 64);
			else if (game->map[game->map_coord.y][game->map_coord.x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
					game->map_coord.x * 64, game->map_coord.y * 64);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
					game->map_coord.x * 64, game->map_coord.y * 64);
		}
	}
}

void	ft_check_win(t_game *game, int x, int y)
{
	if (check_is_all_collected(game) == 1 && game->map[y][x] == 'E')
	{
		ft_printf("You win! Moves: %d\n", game->moves);
		ft_destroy_window(game);
	}
}

void	ft_update_player_position(t_game *game, int x, int y)
{
	if (game->player.x == game->exit.x && game->player.y == game->exit.y)
		game->map[game->player.y][game->player.x] = 'E';
	else
		game->map[game->player.y][game->player.x] = '0';
	game->player.x = x;
	game->player.y = y;
	game->map[y][x] = 'P';
	ft_map_draw(game);
}

int	ft_move_player(t_game *game, int dx, int dy)
{
	int	x;
	int	y;

	x = game->player.x + dx;
	y = game->player.y + dy;
	if (game->map[y][x] == 'E' && check_is_all_collected(game) == 0)
	{
		return (0);
	}
	if (x >= 0 && x < game->map_size_x && y >= 0 && y < game->map_size_y
		&& game->map[y][x] != '1')
	{
		ft_check_win(game, x, y);
		ft_update_player_position(game, x, y);
		return (1);
	}
	return (0);
}
