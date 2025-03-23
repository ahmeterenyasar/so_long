/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:20:17 by ayasar            #+#    #+#             */
/*   Updated: 2025/03/13 14:08:24 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_rectangle(char **map, t_game *game)
{
	int	i;
	int	len;
	int	j;

	len = 0;
	while (map[0][len] && map[0][len] != '\n')
		len++;
	game->map_size_x = len;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (j != len)
			ft_handle_map_error(game, map, "Error: Map is not rectangle\n");
		i++;
	}
}

void	ft_check_characters(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("10PEC\n", map[i][j]))
				ft_handle_map_error(game, map, "Error: Invalid item in map\n");
			j++;
		}
		i++;
	}
}

void	ft_check_wall(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_size_x)
	{
		if (map[0][i] != '1' || map[game->map_size_y - 1][i] != '1')
			ft_handle_map_error(game, map, "Error: The wall has a gap\n");
		i++;
	}
	i = 1;
	while (i < game->map_size_y - 1)
	{
		if (map[i][0] != '1' || map[i][game->map_size_x - 1] != '1')
			ft_handle_map_error(game, map, "Error: The wall has a gap\n");
		i++;
	}
}

void	ft_check_components(char **map, t_game *game)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	i = -1;
	p = 0;
	e = 0;
	c = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'C')
				c++;
		}
	}
	if (p != 1 || e != 1 || c < 1)
		ft_handle_map_error(game, map, "Error: Invalid num of items in map\n");
}
