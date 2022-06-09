/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_tester.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:19:04 by afonso            #+#    #+#             */
/*   Updated: 2022/06/08 19:00:15 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	main(void)
{
	t_game	game;
	// char	line[] = "1000EC001\n";
	// char	line2[] = "100P00011\n";
	int		fd;
	int		i;
	char	*saved;

	game.window_height = 4;
	i = 0;
	fd = open("./mapa1.ber", O_RDONLY);
	while (i < 5)
	{
		ft_printf("saved:%p\n", saved = get_next_line(fd));
		ft_printf("strlen:%d\n", ft_strlen(saved));
		if (saved)
			free (saved);
		i++;
	}
	game.mlx_ptr = mlx_init();
	ft_printf("*********testing find_map_height()*********\n");
	ft_printf("mapa1 tem 4 colunas || find_map_height() diz: %d\n", find_map_height("./mapa1.ber"));
	ft_printf("\n*********Testing make_map()*********\n");
	make_map(&game, "./mapa1.ber");
	ft_printf("\n*********Testing Check_dimensions()*********\n");
	ft_printf("mapa1 tem boas dimensoes || Check_dimensions diz:%d\n", check_dimensions(&game));
	free_map(&game);
	mlx_destroy_window(game.mlx_ptr, game.window);
	free(game.mlx_ptr);
}
