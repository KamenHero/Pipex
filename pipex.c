/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:02:19 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/16 20:41:37 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_fderror(t_data fd)
{
	if (fd.infile < 0 || fd.outfile < 0)
	{
		perror("pipex");
		exit(0);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	fd;
	pid_t	i;
	pid_t	j;
	char	**path;

	j = 0;
	if (argc != 5)
		(ft_putendl_fd("Arguments must be 5", 2), exit(1));
	pipe(fd.end);
	path = NULL;
	fd.infile = open(argv[1], O_RDONLY, 0644);
	fd.outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_fderror(fd);
	i = fork();
	if (i < 0)
		(perror(""), exit(0));
	else if (i == 0)
		firstchild(env, path, argv, fd);
	else
		j = ft_fork(env, path, argv, fd);
	close(fd.end[1]);
	close(fd.end[0]);
	while (wait(NULL) != -1)
		;
	return (0);
}
