/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:24:08 by arobu             #+#    #+#             */
/*   Updated: 2022/11/10 04:17:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joint_string;
	char	*s1_ptr;
	size_t	len;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	s1_ptr = s1;
	len = (ft_strlen(s1) + ft_strlen(s2));
	joint_string = (char *)malloc(sizeof(char) * (len + 1));
	while (*s1 != '\0')
		*joint_string++ = *s1++;
	while (*s2 != '\0')
		*joint_string++ = *s2++;
	*joint_string = '\0';
	free(s1_ptr);
	return (joint_string - len);
}
