/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:55:27 by ayasar            #+#    #+#             */
/*   Updated: 2025/03/13 12:22:08 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_cord
{
	int		x;
	int		y;
}			t_cord;

typedef struct s_game
{
	t_cord	player;
	t_cord	exit;
	t_cord	collect;
	t_cord	map_coord;
	char	**map;
	int		map_size_x;
	int		map_size_y;
	int		moves;
	void	*mlx;
	void	*win;

	void	*img_player;
	void	*img_exit;
	void	*img_collect;
	void	*img_wall;
	void	*img_floor;
}			t_game;

void		ft_validate_filename(char *file_name);
void		ft_init_game(t_game *game);
void		ft_check_map(t_game *game, char *filename);
void		ft_map_size_y(int fd, t_game *game);
void		ft_validate_map(char **map, t_game *game);
void		ft_check_rectangle(char **map, t_game *game);
void		ft_check_characters(char **map, t_game *game);
void		ft_check_wall(char **map, t_game *game);
void		ft_check_components(char **map, t_game *game);

void		ft_check_valid_path(char **map, t_game *game);
void		ft_flood_fill(char **map, int player_x, int player_y, t_game *game);

void		ft_locate_player(t_game *game, char **map);
void		ft_locate_exit(t_game *game, char **map);
void		ft_locate_collectables(t_game *game, char **map);

void		ft_free_main(t_game *game);
void		ft_free_map(char **map);
void		ft_handle_map_error(t_game *game, char **map, char *error_message);

void		ft_game_starter(t_game *game);
void		ft_load_images(t_game *game);
void		ft_map_draw(t_game *game);
int			ft_key_handler(int keycode, t_game *game);
int			ft_move_player(t_game *game, int x, int y);
int			ft_destroy_window(t_game *game);

int			check_is_all_collected(t_game *game);
char		**ft_map_copy(int fd1, int fd2, t_game *game);

#endif