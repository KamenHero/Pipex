/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:31:53 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/13 22:44:16 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_data
{
	int		infile;
	int		outfile;
	int		end[2];
	int		prev_fd;
	int		j;
	pid_t	i;
}			t_data;

char	**firstpath(char **env);
void	execc(char **path, char *argv, char **env);
void	firstchild(char **env, char **path, char **argv, t_data fd);
void	secondchild(char **env, char **path, char **argv, t_data fd);
void	ft_fork(char **env, char **path, char *argv, t_data *fd);
void	falsepath(char *cmd);
int		ft_access(char *argv);
void	ft_fderror(t_data fd);
void	ft_initialfds(t_data *fd, char **path, char **argv, int argc);

#endif
