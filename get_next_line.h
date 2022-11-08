/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:13:28 by arobu             #+#    #+#             */
/*   Updated: 2022/11/08 21:35:11 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define GNL_LINEBREAK '\n'
# define GNL_EOF_NULL '\0'
# define GNL_ERROR -1
# define GNL_EOF 0

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_gnl
{
	struct s_gnl	*next;
	char			*line;
	char			*next_line;
	int				fd;
}				t_gnl;

void	create_node(t_gnl **node);	
size_t	ft_strlen(const char *s);

char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char const *str, unsigned int start_index, size_t len);
char	*ft_strdup(const char *string);
char	*ft_strchr(char *str, int c);


#endif