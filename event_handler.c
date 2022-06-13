/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:30:59 by afonso            #+#    #+#             */
/*   Updated: 2022/06/13 14:24:59 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	event_handler(int keycode, t_game *game, t_image *images)
{
	ft_printf("%d\n", keycode);
	if (keycode == 65307)
	{
		ft_printf("OLA\n");
		unload_assets(game, images);
	}
	return (0);
}
