/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:12:00 by arobu             #+#    #+#             */
/*   Updated: 2022/11/08 22:12:14 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_node(t_gnl **node)
{
	if (!*node)
	{
		(*node) = (t_gnl *)malloc(sizeof(t_gnl));
		(*node) -> line = NULL;
		(*node) -> next_line = NULL;
		(*node) -> next = NULL;
	}
}

char	*ft_process_buffer(int fd)
{
	char	*buffer;
	char	*tmp_line;
	char	*tmp_ref;
	
	tmp_line = (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	while (ft_strchr(buffer, GNL_LINEBREAK) == NULL)
	{
		read(fd, buffer, BUFFER_SIZE);
		if (!tmp_line)
			tmp_line = ft_strdup(buffer);
		else
		{
			tmp_ref = tmp_line;
			tmp_line = ft_strjoin(tmp_ref, buffer);
			free(tmp_ref);
		}
	}
	free(buffer);
	return (tmp_line);
}

void	ft_get_data(t_gnl **node, int fd)
{
	char	*tmp_line;
	char	*tmp;
	size_t	position;
	size_t	left_over;
	
	position = 0;
	left_over = 0;
	tmp_line = ft_process_buffer(fd);
	position = ft_strchr(tmp_line, GNL_LINEBREAK) - tmp_line + 1;
	left_over = ft_strlen(tmp_line) - position;
	if ((*node) -> next_line == NULL)
	{
		(*node) -> line = ft_substr(tmp_line, 0, position);
		(*node) -> next_line = ft_substr(tmp_line, position, left_over);
	}


	free(tmp_line);
}

char	*get_next_line(int fd)
{
	static t_gnl	*gnl_node;
	create_node(&gnl_node);
	
	printf("Next Line: %s\n", gnl_node -> next_line);
	ft_get_data(&gnl_node, fd);
	
	return (gnl_node -> line);
}

int main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);

	return (0);
}