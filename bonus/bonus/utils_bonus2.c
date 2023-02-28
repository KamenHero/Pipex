/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:32:28 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/16 22:27:59 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(char **argvcmd)
{
	ft_putstr_fd("pipex: Command not found: ", 2);
	ft_putendl_fd(argvcmd[0], 2);
	exit(0);
}
