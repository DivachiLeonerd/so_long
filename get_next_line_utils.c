/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:20:04 by afonso            #+#    #+#             */
/*   Updated: 2022/05/12 16:42:51 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long long	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		counter++;
		str++;
	}
	return (counter);
}

char	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*array;

	array = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		if (array[i] == (unsigned char)c)
			return ((char *)&array[i]);
		i++;
	}
	return (NULL);
}

void	checking_buffer(char *buf)
{
	int	index;
	int	new_index;

	index = 0;
	new_index = 0;
	if (!buf)
		return ;
	while (buf[index] != '\n' && index < BUFFER_SIZE)
		buf[index++] = 0;
	while (index < BUFFER_SIZE)
	{
		buf[index++] = 0;
		buf[new_index++] = buf[index];
	}
	return ;
}

char	*ft_substr(char *s, unsigned long long start, unsigned long long len)
{
	char				*str;
	unsigned long long	i;
	unsigned long long	j;

	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
	{
		if (start + len < ft_strlen(s))
			str = malloc(sizeof(char) * (len + 1));
		else
			str = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	}
	else
		str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while ((start < ft_strlen(s) && i < start + len && s[i] != '\0'))
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char *saved, char *buf)
{
	int		i;
	int		j;
	char	*alloc;

	if (!saved || !buf)
		return (NULL);
	i = ft_strlen(saved);
	j = ft_strlen(buf);
	alloc = malloc((i + j + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	i = 0;
	while (saved[i])
	{
		alloc[i] = saved[i];
		i++;
	}
	j = 0;
	while (buf[j] && buf[j] != '\n')
		alloc[i++] = buf[j++];
	if (buf[j] == '\n')
		alloc[i++] = buf[j++];
	alloc[i] = '\0';
	free (saved);
	return (alloc);
}
