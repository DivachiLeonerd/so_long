/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:19:38 by afonso            #+#    #+#             */
/*   Updated: 2022/06/14 17:20:47 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		free_map(t_game *game, int max_index);

int	main(int argc, char **argv)
{
	t_game	game;
	char	*berfile;
	t_image	images[5];

	berfile = argv[1];
	ft_printf("berfile:%s\n", berfile);
	if (!berfile || argc != 2)
		return (0);
	game.mlx_ptr = mlx_init();
	if (!check_map(berfile, &game))
		return (0);
	// images[2].image = mlx_xpm_file_to_image(game.mlx_ptr,
	// 		"player.xpm", &(game.image_x), &(game.image_y));
	// images[0].image = mlx_xpm_file_to_image(game.mlx_ptr,
	// 		"floor.xpm", &(game.image_x), &(game.image_y));
	// game.wall_image = mlx_xpm_file_to_image(game.mlx_ptr,
	// 		"wall.xpm", &(game.image_x), &(game.image_y));
	// game.collectable_image = mlx_xpm_file_to_image(game.mlx_ptr,
	// 		"collectable.xpm", &(game.image_x), &(game.image_y));
	// mlx_put_image_to_window(game.mlx_ptr, game.window,
	// 	game.wall_image, 0, 0);
	// mlx_put_image_to_window(game.mlx_ptr, game.window,
	// 	images[0].image, 0, 0);
	// mlx_put_image_to_window(game.mlx_ptr, game.window,
	// 	images[2].image, 16, 16);
	// mlx_put_image_to_window(game.mlx_ptr, game.window,
	// 	game.collectable_image, 0, 64);
	// mlx_put_image_to_window(game.mlx_ptr, game.window,
	// 	game.exit_image, 64, 64);
	load_game(images, &game);
	mlx_key_hook(game.window, event_handler, &game);
	mlx_hook(game.window, 17, 1L << 2, close_x_window, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

void	free_map(t_game *game, int max_index)
{
	int	height;

	height = 0;
	while (height <= max_index)
	{
		free(game->map[height]);
		height++;
	}
	return ;
}

