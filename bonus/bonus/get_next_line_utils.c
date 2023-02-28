/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:07:41 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/17 21:15:57 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdupp(char *s)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_strlenn(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	char	*str;

	if (!s1)
		return (ft_strdupp(s2));
	if (!s2)
		return (NULL);
	lens1 = ft_strlenn(s1);
	lens2 = ft_strlenn(s2);
	str = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
		str[i + lens1] = s2[i];
	str[lens1 + i] = '\0';
	free (s1);
	return (str);
}

int	ft_strchrr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	if (s[i] == '\0')
		return (0);
	return (0);
}
