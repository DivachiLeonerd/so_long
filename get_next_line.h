/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:33:44 by afonso            #+#    #+#             */
/*   Updated: 2022/05/17 12:50:36 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char				*get_next_line(int fd);
char				*ft_substr(char *s, unsigned long long start,
						unsigned long long len);
char				*ft_realloc(char *saved_string, char *buffer,
						int start, int end);
char				*ft_memchr(const void *s, int c, size_t n);
void				checking_buffer(char *buf);
char				*get_line(char *buf, int index, int fd, int mode);
unsigned long long	ft_strlen(const char *str);
char				*ft_strjoin(char *saved, char *buf);
#endif
