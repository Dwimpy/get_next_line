/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:13:28 by arobu             #+#    #+#             */
/*   Updated: 2022/11/06 17:31:44 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define GNL_LINEBREAK '\n'
# define GNL_EOF_NULL '\0'
# define GNL_ERROR 0
# define GNL_EOF 0

typedef struct s_gnl
{
	t_gnl			*gnl;
	t_gnl			*next;
	char			*line;
	int				fd;
}				t_gnl;

#endif