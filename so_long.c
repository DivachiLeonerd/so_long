/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:19:38 by afonso            #+#    #+#             */
/*   Updated: 2022/05/20 12:57:12 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*image;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "a window do Afonso");
	image = mlx_new_image(mlx, 1920, 1080);
	mlx_loop(mlx);
}
