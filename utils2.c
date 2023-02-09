/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:10:19 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/10 00:11:36 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	ft_fork(char **env, char **path, char **argv, t_data fd)
{
	pid_t	j;

	j = fork();
	if (j < 0)
		perror("Error : fork2");
	else if (!j)
		secondchild(env, path, argv, fd);
	return (j);
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
