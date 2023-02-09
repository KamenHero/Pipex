/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:02:19 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/10 00:11:45 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	fd;
	pid_t	i;
	int		status;
	pid_t	j;
	char	**path;

	j = 0;
	if (argc != 5)
		exit(1);
	pipe(fd.end);
	path = NULL;
	fd.infile = open(argv[1], O_RDONLY, 0644);
	fd.outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd.infile < 0 || fd.outfile < 0)
		perror("Error: fd");
	i = fork();
	if (i < 0)
		perror("Error : fork1");
	else if (i == 0)
		firstchild(env, path, argv, fd);
	else
		j = ft_fork(env, path, argv, fd);
	close(fd.end[1]);
	waitpid(j, &status, 0);
	exit(WEXITSTATUS(status));
}
