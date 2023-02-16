/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:31:53 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/16 20:30:00 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_data
{
	int		infile;
	int		outfile;
	int		end[2];
	int		prev_fd;
	int		j;
	char	**path;
	pid_t	x;
	pid_t	i;
}			t_data;

char		**firstpath(char **env);
void		execc(char **path, char *argv, char **env);
void		firstchild(char **env, char **path, char **argv, t_data fd);
void		secondchild(char **env, char **path, char **argv, t_data fd);
void		ft_fork(char **env, char **path, char *argv, t_data *fd);
void		falsepath(char *cmd);
int			ft_access(char *argv);
void		ft_fderror(t_data fd);
void		ft_initialfds(t_data *fd, char **path, char **argv, int argc);
void		ft_error(char **argvcmd);
void		ft_here_doc(t_data *fd, char **argv);
void		execcforhere(char **path, char **env, char *argv, t_data *fd);
void		ft_initialfds2(t_data *fd, char **path, char **argv);
int			ft_strcmp(char *line, char *str);

#endif
