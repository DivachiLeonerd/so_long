/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:19:38 by afonso            #+#    #+#             */
/*   Updated: 2022/05/23 12:06:03 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*image;
	void	*window;
	int		width = 128;
	int		height = 128;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "a window do Afonso");
	image = mlx_xpm_file_to_image(mlx, "./cursed-protagonist.xpm", &width, &height);
	ft_printf("%p\n", image);
	mlx_put_image_to_window(mlx, window, image, 1920, 1080);
	mlx_loop(mlx);
}
