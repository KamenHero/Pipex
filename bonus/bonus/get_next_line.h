/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:04:07 by oryadi            #+#    #+#             */
/*   Updated: 2022/11/08 18:04:10 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlenn(char *s);
char	*ft_strjoinn(char *s1, char *s2);
int		ft_strchrr(char *s);
char	*ft_line(char *str, int fd);
char	*ft_spliter(char *line);
char	*ft_first(char *str);
char	*ft_strdupp(char *s);

#endif
