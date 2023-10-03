/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:32:48 by dvalino-          #+#    #+#             */
/*   Updated: 2023/09/04 13:32:51 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	dup_previous(t_data *data)
{
	dup2(data->previous, STDIN_FILENO);
	close(data->previous);
}

/*Revisar lineas*/

int	check_cmd_access(char ***cmd, int i)
{
	if (!cmd[i][0])
		return (-1);
	if (cmd[i][0][0] == '/')
	{
		if (access(cmd[i][0], F_OK | R_OK) != -1)
			return (1);
		return (-1);
	}
	return (0);
}

char	*access_cmd(char ***cmd, char **envp, int i)
{
	int		x;
	char	*tmp;
	char	*path;
	char	**envp_paths;

	x = -1;
	if (check_cmd_access(cmd, i) == -1)
		return (NULL);
	if (check_cmd_access(cmd, i) == 1)
		return (ft_strdup(cmd[i][0]));
	envp_paths = find_path(envp);
	if (!envp_paths)
		return (free(envp_paths), NULL);
	while (envp_paths[++x])
	{
		tmp = ft_strjoin(envp_paths[x], "/");
		path = ft_strjoin(tmp, cmd[i][0]);
		free(tmp);
		if (access(path, F_OK | R_OK) != -1)
			return (free_split(envp_paths), path);
		free(path);
	}
	path = ft_strdup(cmd[i][0]);
	return (free_split(envp_paths), path);
}

char	**find_path(char **envp)
{
	int	x;

	x = 0;
	while (envp[x])
	{
		if (ft_strncmp(envp[x], "PATH=", 5) == 0)
			return (ft_split(envp[x], ':'));
		x++;
	}
	return (NULL);
}

int	make_cmd(char **argv, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 2;
	data->cmd_args = malloc(sizeof(char **) * data->cmd_count);
	if (!data->cmd_args)
		return (-1);
	while (x < data->cmd_count)
	{
		data->cmd_args[x] = ft_split(argv[y], ' ');
		if (!data->cmd_args[x])
			return (-1);
		x++;
		y++;
	}
	return (0);
}
