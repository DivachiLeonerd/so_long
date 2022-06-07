/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:59:44 by afonso            #+#    #+#             */
/*   Updated: 2022/06/07 15:51:36 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lookfor_characters(char *line)
{
	static int	exit;
	static int	collects;
	static int	player;
	int			sum;

	while (*line)
	{
		if (exit < 2 && collects < 2 && player < 2)
		{
			if (*line == 'E')
				exit++;
			if (*line == 'C')
				collects++;
			if (*line == 'P')
				player++;
		}
		line++;
	}
	sum = exit + collects + player;
	if (!*line && sum == 3)
		return (1);
	return (0);
}

int	find_map_height(char *bermap)
{
	int		height;
	int		fd;
	char	*saved;

	height = 0;
	fd = open(bermap, O_RDONLY);
	if (fd < 1)
		return (0);
	saved = get_next_line(fd);
	while ((saved && (saved[ft_strlen(saved) - 1]) == '\n'))
	{
		if (ft_strlen(saved) > 0)
		{
			free(saved);
			saved = get_next_line(fd);
		}
		height++;
		ft_printf("Acabou find_map_height com return de %d\n", height);
	}
	return (height);
}

int	check_dimensions(t_game *game)
{
	int	height;
	int	character_num;

	height = -1;
	character_num = 0;
	while (height < game->window_height)
	{
		height++;
		character_num = lookfor_characters(game->map[height]);
		if (ft_strlen(game->map[height]) != ft_strlen(game->map[height - 1]))
			return (ft_printf("erro. mapa inválido @check_dimensions()\n"));
		game->window_width = ft_strlen(game->map[0]);
		if (height * 64 <= 1080)
		{
			if (game->window_width * 64 > 1920)
				return (0);
		}
		else
			return (0);
	}
	if (!character_num)
		return (0);
	return (1);
}

void	make_map(t_game *game, int fd, char *bermap)
{
	int		fd2;
	char	*saved;
	int		i;

	i = 0;
	game->window_height = find_map_height(bermap);
	fd2 = open(bermap, O_RDONLY);
	if (fd2 < 1)
		return ;
	saved = get_next_line(fd2);
	if (!saved)
		return ;
	game->window_width = ft_strlen(saved);
	game->map = malloc(game->window_height * sizeof(char *) + 1);
	game->map[game->window_height] = 0;
	while (i < game->window_height)
		game->map[i++] = get_next_line(fd);
	game->window = mlx_new_window(game->mlx_ptr, game->window_width * 64,
			game->window_height * 64, "so_long");
	close (fd2);
	return ;
}

int	check_map(char *bermap, t_game *game)
{
	t_ull				is_ber;
	int					fd;

	ft_printf("Inicio de check_map\n");
	if (!bermap)
		return (0);
	is_ber = (t_ull)ft_strnstr(bermap, ".ber", ft_strlen(bermap));
	if (is_ber == 0)
		return (0);
	fd = open(bermap, O_RDONLY);
	if (fd < 0)
		return (0);
	make_map(game, fd, bermap);
	if (!check_dimensions(game))
		return (0);
	return (1);
	close (fd);
}
