/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:16:41 by afonso            #+#    #+#             */
/*   Updated: 2022/06/17 13:33:46 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_player_move(t_game *game, int keycode);
int	win_game(t_game *game);

void	player_move(t_game *game, int keycode)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (keycode == 13)
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->images[7].image, game->player_x * 64, game->player_y * 64);
	if (keycode == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->images[6].image, game->player_x * 64, game->player_y * 64);
	if (keycode == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->images[2].image, game->player_x * 64, game->player_y * 64);
	if (keycode == 2)
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->images[2].image, game->player_x * 64, game->player_y * 64);
	if (game->map[game->player_y][game->player_x] == 'C')
		game->collect_num--;
	if (!(game->collect_num))
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->images[2].image, game->exit_x * 64, game->exit_y * 64);
	if (game->map[game->player_y][game->player_x] == 'E')
		if (!(game->collect_num))
			win_game(game);
	x = -(keycode == 2) + (keycode == 0);
	y = (keycode == 13) + -(keycode == 1);
	mlx_put_image_to_window(game->mlx_ptr, game->window,
		game->images[0].image, (game->player_x + x) * 64,
		(game->player_y + y) * 64);
	return ;
}

int	can_player_move(t_game *game, int keycode)
{
	if (keycode == 13)
	{
		if (game->map[game->player_y - 1][game->player_x] != '1')
			return (game->player_y--);
	}
	if (keycode == 0)
	{
		if (game->map[game->player_y][game->player_x - 1] != '1')
			return (game->player_x--);
	}
	if (keycode == 1)
	{
		if (game->map[game->player_y + 1][game->player_x] != '1')
			return (game->player_y++);
	}
	if (keycode == 2)
	{
		if (game->map[game->player_y][game->player_x + 1] != '1')
			return (game->player_x++);
	}
	return (-1);
}

int	win_game(t_game *game)
{
	ft_printf("Acertou miseravel\n");
	return (close_x_window(game));
}
