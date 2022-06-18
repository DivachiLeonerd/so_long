/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:30:59 by afonso            #+#    #+#             */
/*   Updated: 2022/06/18 21:04:22 by atereso-         ###   ########.fr       */
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
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
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
					game->window, game->images[4].image, game->exit_x * 64,//exit coordinates hard coded
					game->exit_y * 64);
			ft_printf("%d\n", ++counter);
		}
	}
	if (keycode == 53)
		close_x_window(game);
	return (0);
}

void	find_exit(t_game *game)
{
	int	j;
	int	i;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
			}
			j++;
		}
		i++;
	}
}
