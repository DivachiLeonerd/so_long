/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:19:58 by afonso            #+#    #+#             */
/*   Updated: 2022/06/06 11:20:24 by afonso           ###   ########.fr       */
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
	int		image_y;
	int		image_x;
	//
	void	*player_image;
	//
	void	*floor_image;
	//
	void	*wall_image;
	//
	void	*policeman_image;
	//
	void	*collectable_image;
	//
	void	*exit_image;
	//
	char	**map;
}t_game;
int		find_map_height(char *bermap);
int		check_map(char *bermap, t_game *game);
void	load_game(t_game *game);
int		ft_printf(char *buf, ...);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strchr(char *str, int chr);
int		lookfor_characters(char *line);
int		check_dimensions(t_game *game);
void	make_map(t_game *game, int fd, char *bermap);
#endif
