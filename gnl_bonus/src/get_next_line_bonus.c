/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:12:00 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 16:26:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	create_node(t_gnl **node, int fd)
{
	(*node) = (t_gnl *)malloc(sizeof(t_gnl));
	(*node)->line = NULL;
	(*node)->fd = fd;
	(*node)->eof_reached = 0;
	(*node)->read_bytes = 1;
}

char	*ft_process_buffer(t_gnl **gnl, char *left_over)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(left_over, GNL_LINEBREAK) && (*gnl)->read_bytes > 0)
	{
		(*gnl)->read_bytes = read((*gnl)->fd, buffer, BUFFER_SIZE);
		if ((*gnl)->read_bytes == GNL_ERROR)
		{
			free(buffer);
			return (NULL);
		}
		buffer[(*gnl)->read_bytes] = '\0';
		left_over = ft_strjoin(left_over, buffer);
		if ((*gnl)->eof_reached)
		{
			free(buffer);
			return (left_over);
		}
	}
	free(buffer);
	return (left_over);
}

char	*ft_get_line(t_gnl **gnl, char *left_over)
{
	size_t	size;

	if (!*left_over)
		return (NULL);
	size = ft_strchr(left_over, GNL_LINEBREAK) - left_over + 1;
	(*gnl)->line = ft_substr(left_over, 0, size);
	return ((*gnl)->line);
}

char	*ft_update_leftover(char *left_over)
{
	size_t	size;
	size_t	str_len;
	char	*left_over_str;

	if (!*left_over)
	{
		free(left_over);
		return (NULL);
	}
	size = ft_strchr(left_over, GNL_LINEBREAK) - left_over + 1;
	str_len = ft_strlen(ft_strchr(left_over, GNL_LINEBREAK));
	left_over_str = ft_substr(left_over, size, str_len);
	free(left_over);
	return (left_over_str);
}

char	*get_next_line(int fd)
{
	static char		*left_over[MAXFILES];
	t_gnl			*gnl;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_node(&gnl, fd);
	left_over[gnl -> fd] = ft_process_buffer(&gnl, left_over[gnl -> fd]);
	if (!left_over[gnl -> fd])
	{
		free(gnl);
		return (NULL);
	}
	if (*left_over[gnl -> fd])
		line = ft_strdup(ft_get_line(&gnl, left_over[gnl -> fd]));
	else
		line = NULL;
	left_over[gnl -> fd] = ft_update_leftover(left_over[gnl -> fd]);
	free(gnl -> line);
	free(gnl);
	return (line);
}

// int main(void)
// {
// 	int fd;
// 	char *str;
// 	fd = open("test.txt", O_RDONLY);
// 	/* 1 */ str = get_next_line(fd);
// 	free(str);
// 	/* 2 */ str = get_next_line(fd);
// 	free(str);
// 	close(fd);
// 			fd = open("test.txt", O_RDONLY);
// 	/* 4 */ get_next_line(fd);
// 	/* 5 */ get_next_line(fd);
// 	/* 6 */ get_next_line(fd);
// 	/* 7 */ get_next_line(fd);
// 	/* 8 */ get_next_line(fd);
// 	 return (0);
// }
