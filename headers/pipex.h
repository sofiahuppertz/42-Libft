/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:23:38 by dvalino-          #+#    #+#             */
/*   Updated: 2023/08/23 16:23:40 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"
# include <fcntl.h>

typedef struct t_data
{
	int		pipefd[2];
	int		in_out_fd[2];
	int		invalid_infile;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
	char	*file[2];
	pid_t	*pid;
	int		previous;
}			t_data;

void	free_split(char **split);
void	end(char *error, t_data *data, int exit_int);
void	dup_previous(t_data *data);
char	*access_cmd(char ***cmd, char **envp, int i);
char	**find_path(char **envp);
int		make_cmd(char **argv, t_data *data);

#endif
