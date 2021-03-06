/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:19:38 by afonso            #+#    #+#             */
/*   Updated: 2022/06/18 21:12:20 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		free_map(t_game *game, int max_index);

int	main(int argc, char **argv)
{
	static t_game	game;
	char			*berfile;

	berfile = argv[1];
	if (!berfile || argc != 2)
		return (0);
	if (check_map(berfile, &game) == -1)
		return (0);
	make_window(&game);
	load_game(game.images, &game);
	find_exit(&game);
	mlx_key_hook(game.window, event_handler, &game);
	mlx_hook(game.window, 17, 1L << 2, close_x_window, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

void	free_map(t_game *game, int max_index)
{
	int	height;

	height = 0;
	while (height < max_index)
	{
		free(game->map[height]);
		height++;
	}
	free(game->map);
	return ;
}
