/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:59:44 by afonso            #+#    #+#             */
/*   Updated: 2022/05/24 15:25:52 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char *bermap)
{
	int			is_ber;
	int			fd;
	char		**map;
	int			height;
	int			strlen;

	height = 0;
	if (!bermap)
		return (NULL);
	is_ber = ft_strnstr(bermap, ".ber", ft_strlen(bermap));
	if (is_ber == 0)
		return (NULL);
	fd = open(bermap, O_RDONLY);
	while (1)
	{
		map[height] = get_next_line(fd);
		strlen = ft_strlen(map[height]);
		if (map[height][strlen] != '\n')
			break ;
		height++;
	}
}

static	int	check_dimensions(char **map, int max_height)
{
	int	height;
	int	width;

	while (height <= max_height)
	{
		height++;
		if (ft_strlen(map[height]) != ft_strlen(map[height - 1]))
			return (ft_printf("erro. mapa inválido\n"));
		width = ft_strlen(map[0]);
	}
}
