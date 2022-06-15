/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:30:59 by afonso            #+#    #+#             */
/*   Updated: 2022/06/15 19:47:20 by atereso-         ###   ########.fr       */
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
	free_map(game, game->window_height);
	mlx_destroy_window(game->mlx_ptr, game->window);
	printf("exited Successfully\n");
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
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		return (1);
	return (0);
}

int	event_handler(int keycode, t_game *game)
{
	static int	counter;

	if (valid_key(keycode))
	{
		ft_printf("Passou valid\n");
		if (can_player_move(game, keycode))
		{
			ft_printf("Passou canplayermove\n");
			if (game->map[game->player_y][game->player_x] != 'E')
			{
				printf("%d :: %d\n",game->player_x, game->player_y);
				mlx_put_image_to_window(game->mlx_ptr, game->window,
					game->images[0].image, game->player_x * 64,
					game->player_y * 64);
			}
			else
				mlx_put_image_to_window(game->mlx_ptr,
					game->window, game->images[4].image, game->player_x * 64,
					game->player_y * 64);
			ft_printf("ola\n");
			player_move(game, keycode);
			ft_printf("%d\n", ++counter);
			mlx_put_image_to_window(game->mlx_ptr, game->window,
				game->images[2].image, game->player_x * 64,
				game->player_y * 64);
		}
	}
	if (keycode == 53)
		close_x_window(game);
	return (0);
}
