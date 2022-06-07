/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:19:38 by afonso            #+#    #+#             */
/*   Updated: 2022/06/07 14:24:37 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		free_map(t_game *game);
static int		exit_game(t_game *game);

int	main(int argc, char **argv)
{
	t_game	game;
	char	*berfile;

	berfile = argv[1];
	ft_printf("berfile:%s\n", berfile);
	game.mlx_ptr = mlx_init();
	if (!berfile)
		return (0);
	if (!check_map(berfile, &game) || argc != 2)
	{
		free_map(&game);
		return (0);
	}
	load_game(&game);
	mlx_key_hook(game.window, exit_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

static	void	free_map(t_game *game)
{
	int	height;

	height = 0;
	while (height < game->window_height)
		free(game->map[height++]);
	free(game->map);
	return ;
}

static	int	exit_game(t_game *game)
{
	free_map(game);
	mlx_destroy_image(game->mlx_ptr, game->player_image);
	mlx_destroy_image(game->mlx_ptr, game->floor_image);
	mlx_destroy_image(game->mlx_ptr, game->wall_image);
	mlx_destroy_image(game->mlx_ptr, game->collectable_image);
	mlx_destroy_image(game->mlx_ptr, game->exit_image);
	mlx_destroy_window(game->mlx_ptr, game->window);
	mlx_destroy_display(game->mlx_ptr);
	perror("free_map");
	exit(0);
}
