/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:59:44 by afonso            #+#    #+#             */
/*   Updated: 2022/06/19 19:41:28 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lookfor_characters(char *line)
{
	static int	exit;
	static int	player;
	static int	collectable;

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
	if (fd == -1)
		return (-1);
	saved = get_next_line(fd);
	while (saved)
	{
		free(saved);
		saved = get_next_line(fd);
		height++;
	}
	close(fd);
	return (height);
}

int	check_bounds(t_game game)
{
	int	i;
	int	j;

	j = 0;
	while (game.map[j])
	{
		i = 0;
		if (game.map[j][0] != '1' || game.map[j][game.window_width - 2] != '1')
			return (-1);
		while (game.map[j][i] == '1')
			i++;
		ft_printf("window_w:%d\n", game.window_width);
		if ((j == 0 || j == game.window_height - 1)
			&& i != game.window_width - 1)
			return (-1);
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
	if (game->window_height * 64 > 1080 || game->window_width * 64 > 1920)
		return (ft_error("Invalid map too big"));
	strlen = ft_strlen(game->map[0]);
	if (check_bounds(*game) < 0)
		return (ft_error("Wall layout is not valid"));
	while (++height < game->window_height)
	{
		character_num = lookfor_characters(game->map[height]);
		if (ft_strlen(game->map[height]) != strlen)
			return (ft_error("Invalid map dimensions"));
	}
	if (character_num <= 0)
		return (ft_error("Invalid Components"));
	game->collect_num = character_num;
	return (1);
}

int	make_map(t_game *game, char *bermap, int fd)
{
	char	*saved;
	int		i;

	i = 0;
	game->window_height = find_map_height(bermap);
	if (game->window_height == -1)
		return (-1);
	game->map = malloc(game->window_height * sizeof(char *) + 1);
	if (!game->map)
		return (-1);
	saved = get_next_line(fd);
	if (!saved)
		return (0);
	game->window_width = ft_strlen(saved);
	game->map[game->window_height] = 0;
	game->map[0] = saved;
	i = 0;
	while (++i < game->window_height)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == 0)
			break ;
	}
	return (i);
}

int	check_map(char *bermap, t_game *game)
{
	t_ull				is_ber;
	int					i;
	int					fd;
 // not writing error
	is_ber = (t_ull)ft_strnstr(bermap, ".ber", ft_strlen(bermap) + 1);
	if (is_ber == 0)
		return (ft_error("Invalid file name"));
	fd = open(bermap, O_RDONLY);
	if (fd == -1)
		return (ft_error(strerror(errno)));
	i = make_map(game, bermap, fd);
	close (fd);
	if (i < 0)
		return (ft_error(strerror(errno)));
	if (i != game->window_height)
	{
		free_map(game, i);
		return (ft_error(strerror(errno)));
	}
	if (check_dimensions(game) == -1)
		return (-1);
	return (0);
}
