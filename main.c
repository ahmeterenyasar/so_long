/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:42:39 by ayasar            #+#    #+#             */
/*   Updated: 2025/03/13 11:04:10 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->exit.x = 0;
	game->exit.y = 0;
	game->collect.x = 0;
	game->collect.y = 0;
	game->map_size_x = 0;
	game->map_size_y = 0;
	game->map_coord.x = 0;
	game->map_coord.y = 0;
	game->map = NULL;
}

void	ft_validate_filename(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	i--;
	if (i < 4 || !(file_name[i] == 'r' && file_name[i - 1] == 'e'
			&& file_name[i - 2] == 'b' && file_name[i - 3] == '.'))
	{
		ft_printf("File name is not valid\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long (map_name).ber\n");
		exit(1);
	}
	ft_validate_filename(argv[1]);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		free(game);
		ft_printf("Error: Memory allocation failed for game\n");
		exit(1);
	}
	ft_init_game(game);
	ft_check_map(game, argv[1]);
	ft_game_starter(game);
	ft_free_main(game);
	return (0);
}
