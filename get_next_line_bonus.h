/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:13:28 by arobu             #+#    #+#             */
/*   Updated: 2022/11/10 04:22:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define GNL_LINEBREAK '\n'
# define GNL_ERROR -1
# define MAXFILES 1024

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_gnl
{
	char			*line;
	int				fd;
	int				read_bytes;
	size_t			eof_reached;
}				t_gnl;

void	create_node(t_gnl **node, int fd);

char	*ft_strdup(const char *string);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *str, unsigned int start_index, size_t len);

size_t	ft_strlen(const char *str);

#endif