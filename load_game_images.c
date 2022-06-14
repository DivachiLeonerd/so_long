/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:53 by afonso            #+#    #+#             */
/*   Updated: 2022/06/14 09:27:29 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_images(t_image *images, t_game *game)
{
	images[0].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"floor.xpm", &(images[0].x), &(images[0].y));
	images[1].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"wall.xpm", &(images[1].x), &(images[1].y));
	images[2].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"player.xpm", &(images[2].x), &(images[2].y));
	images[3].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"collectable.xpm", &(images[3].x), &(images[3].y));
	images[4].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"exit.xpm", &(images[4].x), &(images[4].y));
}

static void	put_images(t_image *images, t_game *game, int line, int column)
{
	if (game->map[line][column] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			images[0].image, (column * images[0].x), (line * images[0].y));
	if (game->map[line][column] == '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			images[1].image, (column * images[1].x), (line * images[1].y));
	}

	if (game->map[line][column] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			images[2].image, (column * images[2].x), (line * images[2].y));
	if (game->map[line][column] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			images[3].image, (column * images[3].x), (line * images[3].y));
	if (game->map[line][column] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			images[4].image, (column * images[4].x), (line * images[4].y));
	return ;
}

void	load_game(t_image *images, t_game *game)
{
	int			line;
	int			column;

	line = 0;
	load_images(images, game);
	while (game->map[line] != 0)
	{
		column = 0;
		printf("line:%d\n", line);
		while (game->map[line][column] != '\n')
		{
			put_images(images, game, line, column++);
			if (game->map[line][column] == 'P')
			{
				game->player_x = line;
				game->player_y = column;
			}
		}
		line++;
	}
	return ;
}
