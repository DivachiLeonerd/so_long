/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:36:36 by afonso            #+#    #+#             */
/*   Updated: 2022/06/20 17:16:38 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *error)
{
	printf("Error\n%s\n", error);
	return (-1);
}

int	check_map(char *bermap, t_game *game)
{
	t_ull				is_ber;
	int					i;
	int					fd;

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