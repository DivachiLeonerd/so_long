/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:47:12 by afonso            #+#    #+#             */
/*   Updated: 2022/06/17 17:18:45 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->window = mlx_new_window(game->mlx_ptr, game->window_width * 64 - 64,
			game->window_height * 64, "Vou ser expulso");
}
