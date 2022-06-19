/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:30:59 by afonso            #+#    #+#             */
/*   Updated: 2022/06/19 19:07:46 by afonso           ###   ########.fr       */
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
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		return (1);
	return (0);
}

int	event_handler(int keycode, t_game *game)
{
	static int	counter;

	mlx_put_image_to_window(game->mlx_ptr,
		game->window, game->images[1].image, 0, 0);
	if (valid_key(keycode))
	{
		if (can_player_move(game, keycode) > -1)
		{
			player_move(game, keycode);
			if (game->collect_num == 0)
				mlx_put_image_to_window(game->mlx_ptr,
					game->window, game->images[4].image, game->exit_x * 64,
					game->exit_y * 64);
			ft_printf("%d\n", ++counter);
			mlx_string_put(game->mlx_ptr, game->window, 10, 20,
				4451500, ft_itoa(counter));
		}
		else
			ft_printf("Invalid Move\n");
	}
	else
		ft_printf("Invalid Key\n");
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
