/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:57:23 by dvalino-          #+#    #+#             */
/*   Updated: 2023/09/04 14:57:54 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	free_split(char **split)
{
	int	x;

	x = 0;
	if (!split)
		return ;
	while (split[x])
	{
		free(split[x]);
		x++;
	}
	free(split);
}

void	free_paths(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cmd_count)
	{
		if (data->cmd_paths[i])
			free(data->cmd_paths[i]);
		i++;
	}
	free(data->cmd_paths);
}

void	end(char *error, t_data *data, int exit_int)
{
	int	x;

	if (exit_int == 0 && error)
		perror(error);
	x = -1;
	if (data->cmd_count > 0)
	{
		while (++x < data->cmd_count)
			free_split(data->cmd_args[x]);
		free(data->cmd_args);
	}
	if (data->cmd_paths)
		free_paths(data);
	if (data->pid)
		free(data->pid);
	if (data->pipefd[0] > 0)
		close(data->pipefd[0]);
	if (data->pipefd[1] > 0)
		close(data->pipefd[1]);
	if (data->in_out_fd[0] > 0)
		close(data->in_out_fd[0]);
	if (data->in_out_fd[1] > 0)
		close(data->in_out_fd[1]);
	if (exit_int == 0)
		exit(EXIT_FAILURE);
}
