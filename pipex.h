/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:03:37 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/10 00:11:33 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	int	infile;
	int	outfile;
	int	end[2];
}		t_data;

char	**firstpath(char **env);
void	execc(char **path, char **argv, char **env);
void	firstchild(char **env, char **path, char **argv, t_data fd);
void	secondchild(char **env, char **path, char **argv, t_data fd);
pid_t	ft_fork(char **env, char **path, char **argv, t_data fd);
void	falsepath(char *cmd);

#endif