/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:30:59 by afonso            #+#    #+#             */
/*   Updated: 2022/06/14 20:01:00 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_player_move(t_game *game, int keycode);

int	unload_assets(t_game *game, t_image *images)
{
	mlx_destroy_image(game->mlx_ptr, images[2].image);
	mlx_destroy_image(game->mlx_ptr, images[0].image);
	mlx_destroy_image(game->mlx_ptr, images[1].image);
	mlx_destroy_image(game->mlx_ptr, images[3].image);
	mlx_destroy_image(game->mlx_ptr, images[4].image);
	free_map(game, game->window_height);
	mlx_destroy_window(game->mlx_ptr, game->window);
	printf("exited Succesfully\n");
	exit(0);
}

int	close_x_window(t_game *game, t_image *images)
{
	mlx_destroy_window(game->mlx_ptr, game->window);
	unload_assets(game, images);
	exit(0);
}

int	valid_key(int keycode)
{
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		return (1);
	return (0);
}

int	event_handler(int keycode, t_game *game, t_image *images)
{
	static int	counter;

	if (valid_key(keycode))
	{
		if (can_player_move(game, keycode))
		{
			ft_printf("ok\n");
			ft_printf("x:%d & y:%d\n", game->player_x, game->player_y);
			mlx_put_image_to_window(game->mlx_ptr, game->window,
				images[0].image, game->player_x * 64, game->player_y * 64);
			ft_printf("ola\n");
			player_move(game, keycode);
			ft_printf("%d\n", ++counter);
			mlx_put_image_to_window(game->mlx_ptr, game->window,
				images[2].image, game->player_x * 64, game->player_y * 64);
		}
	}
	if (keycode == 65307)
	{
		ft_printf("OLA\n");
		unload_assets(game, images);
	}
	return (0);
}
