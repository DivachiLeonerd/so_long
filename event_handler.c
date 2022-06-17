/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:30:59 by afonso            #+#    #+#             */
/*   Updated: 2022/06/17 19:01:33 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	unload_assets(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->images[2].image);
	mlx_destroy_image(game->mlx_ptr, game->images[0].image);
	mlx_destroy_image(game->mlx_ptr, game->images[1].image);
	mlx_destroy_image(game->mlx_ptr, game->images[3].image);
	mlx_destroy_image(game->mlx_ptr, game->images[4].image);
	mlx_destroy_image(game->mlx_ptr, game->images[5].image);
	mlx_destroy_image(game->mlx_ptr, game->images[6].image);
	mlx_destroy_image(game->mlx_ptr, game->images[7].image);
	free_map(game, game->window_height);
	mlx_destroy_window(game->mlx_ptr, game->window);
	ft_printf("exited Successfully\n");
	exit(0);
}

int	close_x_window(t_game *game)
{
	unload_assets(game);
	printf("Exited successfully\n");
	exit(0);
}

int	valid_key(int keycode)
{
	ft_printf("keycode:%d\n", keycode);
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		return (1);
	return (0);
}

int	event_handler(int keycode, t_game *game)
{
	static int	counter;

	if (valid_key(keycode))
	{
		if (can_player_move(game, keycode) > -1)
		{
			player_move(game, keycode);
			if (game->collect_num == 0)
				mlx_put_image_to_window(game->mlx_ptr,
					game->window, game->images[4].image, 6 *64,//exit coordinates hard coded
					1 * 64);
			// else if (game->map[game->player_y][game->player_x] != 'E')
			// {
			// 	mlx_put_image_to_window(game->mlx_ptr, game->window,
			// 		game->images[0].image, game->player_x * 64,
			// 		game->player_y * 64);
			// }
			ft_printf("%d\n", ++counter);
		}
	}
	if (keycode == 53)
		close_x_window(game);
	return (0);
}
