/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:24:08 by arobu             #+#    #+#             */
/*   Updated: 2022/11/08 15:56:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	while (str && *str != '\0')
	{
		if ((unsigned char) *str == (unsigned char) c)
			return (str);
		str++;
	}
	if ((unsigned char) *str == (unsigned char) c)
		return (str);
	return (NULL);
}