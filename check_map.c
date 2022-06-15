/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:59:44 by afonso            #+#    #+#             */
/*   Updated: 2022/06/15 19:31:48 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lookfor_characters(char *line)
{
	static int	exit;
	static int	player;
	static int	collectable;
	int			sum;

	sum = 0;
	while (*line)
	{
		if (*line == 'E')
			exit++;
		if (*line == 'P')
			player++;
		if (*line == 'C')
			collectable++;
		line++;
	}
	if (exit == 1 && player == 1 && collectable >= 1)
		return (collectable);
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

int	check_upper_lower_bounds(t_game game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (game.map[j])
	{
		i = 0;
		while (game.map[j][i] == '1')
			i++;
		if ((char *)&i != &game.map[0][(ft_strlen(game.map[0]) - 2)])
		{
			ft_printf("formato invalido @check_upper_lower_bounds()\n");
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_dimensions(t_game *game)
{
	int		height;
	int		character_num;
	t_ull	strlen;

	height = -1;
	character_num = 0;
	while (++height < game->window_height)
	{
		character_num = lookfor_characters(game->map[height]);
		strlen = ft_strlen(game->map[height]);
		if (ft_strlen(game->map[height]) != strlen)
			return (ft_printf("erro. mapa inválido @check_dimensions()\n"));
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
	make_window(game);
	game->collect_num = character_num;
	return (1);
}

int	make_map(t_game *game, char *bermap)
{
	int		fd2;
	char	*saved;
	int		i;

	i = 0;
	game->window_height = find_map_height(bermap);
	fd2 = open(bermap, O_RDONLY);
	if (fd2 < 1)
		return (0);
	saved = get_next_line(fd2);
	if (!saved)
		return (0);
	game->window_width = ft_strlen(saved);
	ft_printf("strlen @make_map:%d\n", game->window_width);
	game->map = malloc(game->window_height * sizeof(char *) + 1);
	if (!game->map)
		return (0);
	game->map[game->window_height] = 0;
	game->map[0] = saved;
	ft_printf("map @make_map():\n");
	i = 0;
	ft_printf("linha:%s\n", game->map[i]);
	while (++i < game->window_height)
	{
		game->map[i] = get_next_line(fd2);
		printf("linha:%s\n", game->map[i]);
		if (game->map[i] == 0)
			return (i);
	}
	ft_printf("window_w:%d || window_h:%d\n", game->window_width * 64, game->window_height * 64);
	close (fd2);
	ft_printf("saindo do make_map()\n");
	return (i);
}

int	check_map(char *bermap, t_game *game)
{
	t_ull				is_ber;
	int					fd;
	int					i;

	ft_printf("Inicio de check_map\n");
	if (!bermap)
		return (0);
	is_ber = (t_ull)ft_strnstr(bermap, ".ber", ft_strlen(bermap));
	if (is_ber == 0)
		return (0);
	fd = open(bermap, O_RDONLY);
	if (fd < 0)
		return (0);
	i = make_map(game, bermap);
	if (i != game->window_height)
		free_map(game, i);
	ft_printf("Antes do checkdimensions()\n");
	if (!check_dimensions(game))
		return (0);
	return (1);
	close (fd);
}
