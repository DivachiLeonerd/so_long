/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:47:12 by afonso            #+#    #+#             */
/*   Updated: 2022/06/13 16:55:10 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_window(t_game *game)
{
	game->window = mlx_new_window(game->mlx_ptr, game->window_width * 64 - 64,
			game->window_height * 64, "Vou ser expulso");
}
