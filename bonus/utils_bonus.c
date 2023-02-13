/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:26:41 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/13 22:12:17 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**firstpath(char **env)
{
	char	**path;
	int		i;
	char	*tmp;

	i = 0;
	while (env[i] && ft_memcmp(env[i], "PATH", 4) != 1)
	{
		if (ft_memcmp(env[i], "PATH", 4) == 0)
			break ;
		i++;
	}
	if (env[i] == NULL)
		return (NULL);
	path = ft_split(env[i] + 5, ':');
	if (!path)
		perror("Error");
	i = 0;
	while (path[i])
	{
		tmp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		free(tmp);
		i++;
	}
	return (path);
}

void	ft_fork(char **env, char **path, char *argv, t_data *fd)
{
	int	x;
	
	x = 0;
	if (fd->i == 0)
	{
		dup2(fd->infile, STDIN_FILENO);
		dup2(fd->end[1], STDOUT_FILENO);
		close(fd->infile);
	}
	else if (fd->i + 2 == fd->j - 2)
	{
		dup2(fd->prev_fd, STDIN_FILENO);
		dup2(fd->outfile, STDOUT_FILENO);
		close(fd->prev_fd);
	}
	else
	{
		dup2(fd->prev_fd, STDIN_FILENO);
		close(fd->prev_fd);
		dup2(fd->end[1], STDOUT_FILENO);
	}
	close(fd->end[1]);
	close(fd->end[0]);
	path = firstpath(env);
	execc(path, argv, env);
}

void	execc(char **path, char *argv, char **env)
{
	int		i;
	char	*cmd;
	char	**argvcmd;

	i = -1;
	argvcmd = ft_split(argv, ' ');
	execve(argvcmd[0], argvcmd, env);
	while (path[++i])
	{
		cmd = ft_strjoin(path[i], argvcmd[0]);
		if (ft_strnstr(argvcmd[0], "./", ft_strlen(cmd)) && access(cmd, F_OK))
			exit(0);
		execve(cmd, argvcmd, env);
		free(cmd);
	}
	if (path[i] == NULL)
		falsepath(argvcmd[0]);
	ft_putstr_fd("pipex: Command not found: ", 2);
	ft_putendl_fd(argvcmd[0], 2);
	exit(127);
}

void	falsepath(char *cmd)
{
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
	{
		if (access(cmd, F_OK) == 0)
		{
			if (access(cmd, R_OK) == 0)
				exit(0);
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd(": permission denied.\n", 2);
			exit(126);
		}
	}
}
