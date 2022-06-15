/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:16:41 by afonso            #+#    #+#             */
/*   Updated: 2022/06/14 19:04:01 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_player_move(t_game *game, int keycode);

void	player_move(t_game *game, int keycode)
{
	if (keycode == 119)
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_y--;
		game->map[game->player_y][game->player_x] = 'P';
	}
	if (keycode == 97)
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_x--;
		game->map[game->player_y][game->player_x] = 'P';
	}
	if (keycode == 115)
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_y++;
		game->map[game->player_y][game->player_x] = 'P';
	}
	if (keycode == 100)
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
		if (game->map[game->player_y - 1][game->player_x] != '1')
			return (1);
	if (keycode == 97)
	{
		if (game->map[game->player_y][game->player_x - 1] != '1')
		{
			return (1);
		}
	}
	if (keycode == 115)
	{
		if (game->map[game->player_y + 1][game->player_x] != '1')
			return (1);
	}
	if (keycode == 100)
	{
		if (game->map[game->player_y][game->player_x + 1] != '1')
			return (1);
	}
	return (0);
}
