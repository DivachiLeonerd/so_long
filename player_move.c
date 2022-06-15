/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:16:41 by afonso            #+#    #+#             */
/*   Updated: 2022/06/15 20:38:19 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_player_move(t_game *game, int keycode);

void	player_move(t_game *game, int keycode)
{
	if (keycode == 13)
	{
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
		game->player_y--;
	}
	if (keycode == 0)
	{
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
		game->player_x--;
	}
	if (keycode == 1)
	{
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
		game->player_y++;
	}
	if (keycode == 2)
	{
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
		game->player_x++;
	}
	if (game->map[game->player_y][game->player_x] == 'C')
		game->collect_num--;
	if (game->map[game->player_y][game->player_x] == 'E')
		if (!(game->collect_num))
			close_x_window(game);
	return ;
}

// void	print_player_move(t_game *game, int x, int y)
// {
// 	if (game->map[y][x] == 'E')
// 	{
// 		mlx_put_image_to_window(game->mlx_ptr, game->window, \
// 		game->images[4].image, x * 64, y * 64);
// 	}
// 	else
// 		mlx_put_image_to_window(game->mlx_ptr, game->window, \
// 	game->images[0].image, x * 64, y * 64);
// 	mlx_put_image_to_window(game->mlx_ptr, game->window, \
// 		game->images[2].image, x * 64, y * 64);
// 	game->player_x = x;
// 	game->player_y = y;
// }

int	can_player_move(t_game *game, int keycode)
{
	// int	x;
	// int	y;

	// (void) game;
	// x = game->player_x -(keycode == 0) + (keycode == 2);
	// y = game->player_y -(keycode == 13) + (keycode == 1);
	// if (x < 0 || x >= game->window_width)
	// 	x = game->player_x;
	// if (y < 0 || y >= game->window_height)
	// 	y = game->player_y;
	// if (game->map[y][x] == '1')
	// {
	// 	x = game->player_x;
	// 	y = game->player_y;
	// }
	// printf("key: %i s: %s\n", keycode, game->map[y]);
	// print_player_move(game, x, y);
	if (keycode == 13)
		if (game->map[game->player_y - 1][game->player_x] != '1')
			return (1);
	if (keycode == 0)
	{
		if (game->map[game->player_y][game->player_x - 1] != '1')
			return (1);
	}
	if (keycode == 1)
		if (game->map[game->player_y + 1][game->player_x] != '1')
			return (1);
	if (keycode == 2)
		if (game->map[game->player_y][game->player_x + 1] != '1')
			return (1);
	return (0);
}
