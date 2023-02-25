/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:13:28 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 16:24:13 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define GNL_LINEBREAK '\n'
# define GNL_ERROR -1

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/**

@typedef {object} t_gnl - A custom struct type representing
 a line of text read from a file descriptor.
@property {string} line - A pointer to a string representing a line of text.
@property {number} fd - An integer file descriptor value.
@property {number} read_bytes - An integer number of bytes read.
*/
typedef struct s_gnl
{
	char			*line;
	int				fd;
	int				read_bytes;
}					t_gnl;

/**

Reads a line of text from the specified file descriptor 
and returns a pointer to the line.
@function
@param {number} fd - An integer file descriptor value.
@returns {string|null} - A pointer to the line read from the file descriptor, 
or null if an error occurred or end-of-file was reached.
*/
char	*get_next_line(int fd);

void	create_node(t_gnl **node, int fd);
char	*ft_strdup_gnl(const char *string);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *str, unsigned int start_index, size_t len);

size_t	ft_strlen_gnl(const char *str);

#endif
