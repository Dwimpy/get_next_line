/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:24:08 by arobu             #+#    #+#             */
/*   Updated: 2022/11/08 20:11:17 by arobu            ###   ########.fr       */
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

char	*ft_substr(char const *str, unsigned int start_index, size_t len)
{
	char	*substring;
	size_t	size;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (ft_strlen(str) < start_index)
		return (ft_strdup(""));
	str += start_index;
	size = ft_strlen(str);
	if (size < len)
		len = size;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (i < len)
	{
		substring[i] = str[i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joint_string;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joint_string = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joint_string)
		return (NULL);
	while (*s1)
		*joint_string++ = *s1++;
	while (*s2)
		*joint_string++ = *s2++;
	*joint_string = '\0';
	return (joint_string - s1_len - s2_len);
}

char	*ft_strdup(const char *string)
{
	char	*destination;
	char	*dst_start;
	int		string_len;

	string_len = ft_strlen(string);
	destination = (char *)malloc(sizeof(char) * (string_len + 1));
	if (!destination)
		return (NULL);
	dst_start = destination;
	while (*string)
	{
		*destination = *string;
		destination++;
		string++;
	}
	*destination = '\0';
	return (dst_start);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}
