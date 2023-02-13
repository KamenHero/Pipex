/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:30:57 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/13 22:46:34 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_data	fd;
	pid_t	j;
	char	**path;

	if (argc < 5)
		(ft_putendl_fd("Arguments must be more than 5", 2), exit(1));
	path = NULL;
	ft_initialfds(&fd, path, argv, argc);
	ft_fderror(fd);
	while (++fd.i + 2 < argc - 1)
	{
		pipe(fd.end);
		j = fork();
		if (j == 0)
			(ft_fork(env, path, argv[fd.i + 2], &fd), exit(0));
		close(fd.end[1]);
		if (fd.prev_fd != -1)
			close(fd.prev_fd);
		fd.prev_fd = fd.end[0];
	}
	while (wait(NULL) != -1)
		;
	return (0);
}

void	ft_initialfds(t_data *fd, char **path, char **argv, int argc)
{
	fd->i = -1;
	fd->j = argc;
	path = NULL;
	fd->prev_fd = -1;
	fd->infile = open(argv[1], O_RDONLY, 0644);
	fd->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
}

int	ft_access(char *argv)
{
	char	**argvcmd;

	argvcmd = ft_split(argv, ' ');
	if (access(argvcmd[0], F_OK) == 0)
	{
		return (0);
	}
	return (1);
}

void	ft_fderror(t_data fd)
{
	if (fd.infile < 0 || fd.outfile < 0)
	{
		perror("");
		exit(0);
	}
}
