/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:16:41 by afonso            #+#    #+#             */
/*   Updated: 2022/06/19 18:57:50 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		can_player_move(t_game *game, int keycode);
int		win_game(t_game *game);
void	print_player(t_game *game, int keycode);

void	player_move(t_game *game, int keycode)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	print_player(game, keycode);
	if (game->map[game->player_y][game->player_x] == 'C')
		game->collect_num--;
	if (game->map[game->player_y][game->player_x] == 'E')
		if ((game->collect_num) == 0)
			win_game(game);
	if (game->map[game->player_y][game->player_x] != 'E')
		game->map[game->player_y][game->player_x] = '0';
	x = -(keycode == D) + (keycode == A);
	y = (keycode == W) - (keycode == S);
	mlx_put_image_to_window(game->mlx_ptr, game->window,
		game->images[0].image, (game->player_x + x) * 64,
		(game->player_y + y) * 64);
	return ;
}

int	can_player_move(t_game *game, int keycode)
{
	if (keycode == W)
		if (game->map[game->player_y - 1][game->player_x] != '1')
			return (game->player_y--);
	if (keycode == A)
		if (game->map[game->player_y][game->player_x - 1] != '1')
			return (game->player_x--);
	if (keycode == S)
		if (game->map[game->player_y + 1][game->player_x] != '1')
			return (game->player_y++);
	if (keycode == D)
		if (game->map[game->player_y][game->player_x + 1] != '1')
			return (game->player_x++);
	return (-1);
}

int	win_game(t_game *game)
{
	ft_printf("Acertou miseravel\n");
	return (close_x_window(game));
}

void	print_player(t_game *game, int keycode)
{
	if (game->map[game->player_y][game->player_x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->images[0].image, game->player_x * 64, game->player_y * 64);
	if (keycode == W)
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->images[7].image, game->player_x * 64, game->player_y * 64);
	if (keycode == A)
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->images[6].image, game->player_x * 64, game->player_y * 64);
	if (keycode == S)
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->images[2].image, game->player_x * 64, game->player_y * 64);
	if (keycode == D)
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->images[2].image, game->player_x * 64, game->player_y * 64);
	return ;
}
