/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:30:59 by afonso            #+#    #+#             */
/*   Updated: 2022/06/14 12:59:33 by afonso           ###   ########.fr       */
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

void	player_move(t_game *game, int keycode)
{
	if (keycode == 119 && can_player_move(game, keycode))
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_y++;
		game->map[game->player_y][game->player_x] = 'P';
	}
	if (keycode == 97 && can_player_move(game, keycode))
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_x--;
		game->map[game->player_y][game->player_x] = 'P';
	}
	if (keycode == 115 && can_player_move(game, keycode))
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_y--;
		game->map[game->player_y][game->player_x] = 'P';
	}
	if (keycode == 100 && can_player_move(game, keycode))
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_x++;
		game->map[game->player_y][game->player_x] = 'P';
	}
	return ;
}

int	can_player_move(t_game *game, int keycode)
{
	if (keycode == 119)
		if (game->map[game->player_y + 1][game->player_x] != '1')
			return (1);
	if (keycode == 97)
		if (game->map[game->player_y][game->player_x - 1] != '1')
			return (1);
	if (keycode == 115)
		if (game->map[game->player_y - 1][game->player_x] != '1')
			return (1);
	if (keycode == 100)
		if (game->map[game->player_y][game->player_x + 1] != '1')
			return (1);
	return (0);
}

int	event_handler(int keycode, t_game *game, t_image *images)
{
	if (valid_key(keycode))
		player_move(game, keycode);
	ft_printf("%d\n", keycode);

	if (keycode == 65307)
	{
		ft_printf("OLA\n");
		unload_assets(game, images);
	}
	return (0);
}
