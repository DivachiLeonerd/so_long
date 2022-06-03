/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:59:44 by afonso            #+#    #+#             */
/*   Updated: 2022/06/02 17:53:33 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	lookfor_characters(char *line)
{
	static int	exit;
	static int	collects;
	static int	player;
	int			sum;

	while (*line != '\n' && *line)
	{
		if (*line == 'E')
			exit++;
		if (*line == 'C')
			collects++;
		if (*line == 'P')
			player++;
	}
	sum = exit + collects + player;
	if (!*line)
	{
		if (sum != 3)
			return (0);
		else
			return (1);
	}
	return (0);
}

static int	find_map_height(char *bermap)
{
	int		height;
	int		fd;
	char	*saved;

	height = 0;
	fd = open(bermap, O_RDONLY);
	if (fd < 1)
		return (0);
	saved = get_next_line(fd);
	while (*saved != '\n' && !(*saved))
	{
		if (*saved)
			free(saved);
		saved = get_next_line(fd);
		height++;
	}
	ft_printf("Acabou find_map_height\n");
	return (height);
}

static	int	check_dimensions(t_game *game)
{
	int	height;
	int	character_num;

	height = -1;
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

static	void	make_map(t_game *game, int fd, char *bermap)
{
	unsigned long long	strlen;
	int					height;

	height = 0;
	strlen = 0;
	game->map = malloc(find_map_height(bermap) * sizeof(char *) + 1);
	while (height < (game->window_height))
	{
		game->map[height] = get_next_line(fd);
		ft_printf("map[%i]:%s\n", height, game->map[height]);
		strlen = (t_ull)(ft_strchr(game->map[height],
					'\n') - game->map[height]);
		if (!(game->map[height][0]))
			break ;
		height++;
	}
	game->window_height = height;
	game->window_width = strlen;
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
