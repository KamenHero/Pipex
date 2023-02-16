/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:45:56 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/09 15:09:50 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *str, int fd)
{
	char	*s;
	int		i;

	i = 1;
	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s)
		return (NULL);
	while (ft_strchrr(str) == 0 && i != 0)
	{
		i = read(fd, s, BUFFER_SIZE);
		if (i == -1)
		{
			free (str);
			free (s);
			return (NULL);
		}
		s[i] = '\0';
		str = ft_strjoinn(str, s);
	}
	free(s);
	return (str);
}

char	*ft_fill(char *line, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_spliter(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	if (!ft_strlenn(str))
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	line = ft_fill(line, str);
	return (line);
}

char	*ft_first(char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free (s);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlenn(s) - i + 1));
	if (!str)
		return (NULL);
	while (s[j + i + 1])
	{
		str[j] = s[j + i + 1];
		j++;
	}
	str[j] = '\0';
	free (s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_line(str, fd);
	if (!str)
		return (NULL);
	line = ft_spliter(str);
	if (str)
		str = ft_first(str);
	return (line);
}
