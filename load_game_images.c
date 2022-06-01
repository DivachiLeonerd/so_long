/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:53 by afonso            #+#    #+#             */
/*   Updated: 2022/06/01 12:17:59 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_images(t_game *game)
{
	game->player_image = mlx_xpm_file_to_image(game->mlx_ptr,
			"player.xpm", &(game->image_x), &(game->image_y));
	game->floor_image = mlx_xpm_file_to_image(game->mlx_ptr,
			"floor.xpm", &(game->image_x), &(game->image_y));
	game->wall_image = mlx_xpm_file_to_image(game->mlx_ptr,
			"wall.xpm", &(game->image_x), &(game->image_y));
	game->collectable_image = mlx_xpm_file_to_image(game->mlx_ptr,
			"collectible.xpm", &(game->image_x), &(game->image_y));
	game->policeman_image = mlx_xpm_file_to_image(game->mlx_ptr,
			"policeman.xpm", &(game->image_x), &(game->image_y));
}

static void	put_images(t_game *game, int line, int column)
{
	if (game->map[line][column] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->wall_image, (column * 64) + 64, (line * 64) + 64);
	if (game->map[line][column] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->wall_image, (column * 64) + 64, (line * 64) + 64);
	if (game->map[line][column] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->wall_image, (column * 64) + 64, (line * 64) + 64);
	if (game->map[line][column] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->wall_image, (column * 64) + 64, (line * 64) + 64);
	if (game->map[line][column] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->wall_image, (column * 64) + 64, (line * 64) + 64);
}

void	load_game(t_game *game)
{
	int	line;
	int	column;

	line = 0;
	load_images(game);
	while (game->map[line][game->window_width] == '\n')
	{
		column = 0;
		while (game->map[line][column] != '\n')
			put_images(game, line, column++);
		line++;
	}
	return ;
}
