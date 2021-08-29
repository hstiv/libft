/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:10:47 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/08 14:05:20 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	make_read_line(char **gnl, int fd, char **line)
{
	size_t		i;
	char		*loc;

	i = ft_strlenc(gnl[fd], '\n');
	*line = ft_strsub(gnl[fd], 0, i);
	if (!(*line))
		return (-1);
	loc = ft_strsub(gnl[fd], i + 1, ft_strlen(gnl[fd]));
	if (!loc)
		return (-1);
	free(gnl[fd]);
	gnl[fd] = loc;
	return (1);
}

static int	make_next_line(char **gnl, char **line, int fd)
{
	int			i;

	i = ft_strlenc(gnl[fd], '\n');
	if (gnl[fd][i] == '\n')
		return (make_read_line(gnl, fd, line));
	*line = ft_strdup(gnl[fd]);
	if (!(*line))
		return (-1);
	ft_strdel(&gnl[fd]);
	return (1);
}

static int	body(char **gnl, char **loc, const int fd, char *buf)
{
	if (!gnl[fd])
		gnl[fd] = ft_strnew(1);
	*loc = ft_strjoin(gnl[fd], buf);
	if (!(*loc))
		return (-1);
	free(gnl[fd]);
	gnl[fd] = *loc;
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*gnl[10240];
	char		buf[BUFF_SIZE + 1];
	int			y;
	char		*loc;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	y = read(fd, (void *)buf, BUFF_SIZE);
	while ((!ft_strchr(gnl[fd], '\n')) && y > 0)
	{
		buf[y] = '\0';
		if (body(gnl, &loc, fd, buf) < 0)
			return (-1);
		if (ft_strchr(gnl[fd], '\n'))
			return (make_read_line(gnl, fd, line));
		y = read(fd, (void *)buf, BUFF_SIZE);
	}
	if (y < 0)
		return (-1);
	else if (y == 0 && (!(gnl[fd]) || gnl[fd][0] == '\0'))
		return (0);
	return (make_next_line(gnl, line, fd));
}
