/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:19:38 by afonso            #+#    #+#             */
/*   Updated: 2022/06/01 15:49:44 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	free_map(t_game *game);

int	main(int argc, char **argv)
{
	t_game	game;
	char	*berfile;

	berfile = argv[1];
	ft_printf("berfile:%s\n", berfile);
	if (!berfile)
		return (0);
	if (!check_map(berfile, &game) || argc != 2)
	{
		free_map(&game);
		return (0);
	}
	game.mlx_ptr = mlx_init();
	game.window = mlx_new_window(game.mlx_ptr, game.window_width,
			game.window_height, "ganda jogao");
	load_game(&game);
	free_map(&game);
	return (0);
}

static	void	free_map(t_game *game)
{
	int	height;

	height = 0;
	while (height < game->window_height)
		free(game->map[height++]);
	return ;
}
