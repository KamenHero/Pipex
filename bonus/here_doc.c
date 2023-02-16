/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:05:51 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/16 20:28:04 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_here_doc(t_data *fd, char **argv)
{
	char	*line;
	int		fds[2];
	char	*del;

	fd->i = 0;
	pipe(fds);
	del = ft_strjoin(argv[2], "\n");
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (ft_strcmp(line, del) == 0)
		{
			free (line);
			close(fds[1]);
			fd->infile = fds[0];
			break ;
		}
		write (fds[1], line, ft_strlen(line));
		free (line);
	}
}

int	ft_strcmp(char *line, char *str)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != str[i])
			return (1);
		i++;
	}
	return (0);
}
