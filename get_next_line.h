/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:13:28 by arobu             #+#    #+#             */
/*   Updated: 2022/11/08 15:59:53 by arobu            ###   ########.fr       */
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

typedef struct s_gnl
{
	struct s_gnl	*next;
	char			*line;
	char			*next_line;
	int				fd;
}				t_gnl;

#endif