/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:03:05 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/16 20:41:31 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	execc(char **path, char **argv, char **env)
{
	int		i;
	char	*cmd;
	char	**argvcmd;

	i = -1;
	argvcmd = ft_split(argv[2], ' ');
	execve(argvcmd[0], argvcmd, env);
	while (path[++i])
	{
		cmd = ft_strjoin(path[i], argvcmd[0]);
		if (ft_strnstr(argvcmd[0], "./", ft_strlen(cmd)) && access(cmd, F_OK))
			ft_error(argvcmd);
		execve(cmd, argvcmd, env);
		free(cmd);
	}
	if (path[i] == NULL)
		falsepath(argvcmd[0]);
	ft_putstr_fd("pipex: Command not found: ", 2);
	ft_putendl_fd(argvcmd[0], 2);
	exit(127);
}

void	firstchild(char **env, char **path, char **argv, t_data fd)
{
	close(fd.end[0]);
	dup2(fd.infile, STDIN_FILENO);
	dup2(fd.end[1], STDOUT_FILENO);
	path = firstpath(env);
	execc(path, argv, env);
}

void	execc2(char **path, char **argv, char **env)
{
	int		i;
	char	*cmd;
	char	**argvcmd;

	i = -1;
	argvcmd = ft_split(argv[3], ' ');
	execve(argvcmd[0], argvcmd, env);
	while (path[++i])
	{
		cmd = ft_strjoin(path[i], argvcmd[0]);
		if (ft_strnstr(argvcmd[0], "./", ft_strlen(cmd)) && access(cmd, F_OK))
			ft_error(argvcmd);
		execve(cmd, argvcmd, env);
		free(cmd);
	}
	if (path[i] == NULL)
		falsepath(argvcmd[0]);
	ft_putstr_fd("pipex: Command not found: ", 2);
	ft_putendl_fd(argvcmd[0], 2);
	exit(127);
}

void	secondchild(char **env, char **path, char **argv, t_data fd)
{
	close(fd.infile);
	close(fd.end[1]);
	dup2(fd.end[0], STDIN_FILENO);
	close(fd.end[0]);
	dup2(fd.outfile, STDOUT_FILENO);
	path = firstpath(env);
	execc2(path, argv, env);
}
