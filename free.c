/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:38:40 by ayasar            #+#    #+#             */
/*   Updated: 2025/03/13 11:04:31 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_main(t_game *game)
{
	if (game && game->map)
		ft_free_map(game->map);
	if (game)
		free(game);
}

void	ft_handle_map_error(t_game *game, char **map, char *error_message)
{
	if (map)
		ft_free_map(map);
	ft_free_main(game);
	game = NULL;
	ft_printf("%s\n", error_message);
	exit(1);
}
