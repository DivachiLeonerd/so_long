/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:19:58 by afonso            #+#    #+#             */
/*   Updated: 2022/06/14 12:50:13 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef unsigned long long	t_ull;
typedef struct game
{
	void	*mlx_ptr;
	void	*window;
	int		window_width;
	int		window_height;
	int		player_y;
	int		player_x;
	char	**map;
}t_game;

typedef struct s_image
{
	void	*image;
	int		x;
	int		y;
}t_image;

int		find_map_height(char *bermap);
int		check_map(char *bermap, t_game *game);
void	load_game(t_image *images, t_game *game);
int		ft_printf(char *buf, ...);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strchr(char *str, int chr);
int		lookfor_characters(char *line);
int		check_dimensions(t_game *game);
int		make_map(t_game *game, char *bermap);
void	free_map(t_game *game, int i);
int		unload_assets(t_game *game, t_image *images);
int		event_handler(int keycode, t_game *game, t_image *images);
int		close_x_window(t_game *game, t_image *images);
void	make_window(t_game *game);
void	player_move(t_game *game, int keycode);
#endif
