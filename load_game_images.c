/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:53 by afonso            #+#    #+#             */
/*   Updated: 2022/06/16 18:59:46 by atereso-         ###   ########.fr       */
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
	images[5].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"mid-atk-action.xpm", &(images[5].x), &(images[5].y));
	images[6].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"playerleft.xpm", &(images[6].x), &(images[6].y));
	images[7].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"playerup.xpm", &(images[7].x), &(images[7].y));
}

static void	put_images(t_image *images, t_game *game, int line, int column)
{
	if (game->map[line][column] == '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			images[1].image, (column * images[1].x), (line * images[1].y));
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			images[0].image, (column * images[0].x), (line * images[0].y));
	if (game->map[line][column] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			images[2].image, (column * images[2].x), (line * images[2].y));
	if (game->map[line][column] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			images[3].image, (column * images[3].x), (line * images[3].y));
	return ;
}

void	load_game(t_image *images, t_game *game)
{
	int			line;
	int			column;

	line = 0;
	ft_printf("Saindo do check_dimensions1()\n");
	load_images(images, game);
		ft_printf("Saindo do check_dimensions2()\n");
	while (game->map[line] != 0)
	{
		column = 0;
		while (game->map[line][column] != '\n')
		{
			ft_printf("Saindo do check_dimensions3()\n");
			put_images(images, game, line, column++);
			if (game->map[line][column] == 'P')
			{
				game->player_x = column;
				game->player_y = line;
			}
			if (game->map[line][column] == 'E')
			{
				game->images[4].x = column;
				game->images[4].x = line;
			}
		}
		line++;
	}
		ft_printf("Saindo do load_game()\n");
	return ;
}
