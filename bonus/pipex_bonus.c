/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:30:57 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/16 23:07:27 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_data	fd;
	pid_t	j;
	char	**path;
	int		status;

	if (argc < 5)
		(ft_putendl_fd("Arguments must be more than 5", 2), exit(1));
	path = NULL;
	(ft_initialfds(&fd, path, argv, argc), ft_fderror(fd, argv));
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
	waitpid(j, &status, 0);
	while (wait(NULL) != -1)
		;
	exit(WEXITSTATUS(status));
	return (0);
}

void	ft_initialfds(t_data *fd, char **path, char **argv, int argc)
{
	fd->i = -1;
	fd->j = argc;
	path = NULL;
	fd->prev_fd = -1;
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		ft_here_doc(fd, argv);
		fd->x = 1;
		fd->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	else
	{
		fd->x = 0;
		fd->infile = open(argv[1], O_RDONLY, 0644);
		fd->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
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

void	ft_fderror(t_data fd, char **argv)
{
	if (fd.infile < 0 )
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putendl_fd(argv[1], 2);
	}
	if (fd.outfile < 0)
	{
		perror("");
		exit(0);
	}
}
