/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:45:01 by dvalino-          #+#    #+#             */
/*   Updated: 2023/08/23 15:45:03 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	ft_init(char **argv, int argc, t_data	*data)
{
	data->file[0] = argv[1];
	data->file[1] = argv[argc - 1];
	data->cmd_count = argc - 3;
	data->cmd_paths = ft_calloc(sizeof(char *), (data->cmd_count + 1));
	data->pid = malloc(sizeof(int) * data->cmd_count);
	if (!data->pid)
		end("malloc", data, 0);
	if (make_cmd(argv, data) < 0)
		end("malloc", data, 0);
}

void	parse_cmd(t_data *data, char **envp)
{
	int		i;

	i = 0;
	while (i < data->cmd_count)
	{
		data->cmd_paths[i] = access_cmd(data->cmd_args, envp, i);
		i++;
	}
}

void	redirection(t_data *data, int i)
{
	if (i != data->cmd_count - 1)
		dup2(data->pipefd[1], STDOUT_FILENO);
	if (i != 0)
		dup_previous(data);
	if (i == 0)
	{
		data->in_out_fd[0] = open(data->file[0], O_RDONLY);
		if (data->in_out_fd[0] == -1)
			end(data->file[0], data, 0);
		dup2(data->in_out_fd[0], STDIN_FILENO);
		close(data->in_out_fd[0]);
	}
	if (i == data->cmd_count - 1)
	{
		data->in_out_fd[0]
			= open(data->file[1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (data->in_out_fd[0] == -1)
			end(data->file[0], data, 0);
		dup2(data->in_out_fd[0], STDOUT_FILENO);
		close(data->in_out_fd[0]);
	}
	close(data->pipefd[1]);
	close(data->pipefd[0]);
}

void	ft_exec(char **envp, t_data *data, int i, char **argv)
{
	if (pipe(data->pipefd) == -1)
		end("pipe", data, 0);
	data->pid[i] = fork();
	if (data->pid[i] == -1)
		end("fork", data, 0);
	if (data->pid[i] == 0)
	{
		redirection(data, i);
		if (data->cmd_paths[i])
			execve(data->cmd_paths[i], data->cmd_args[i], envp);
		ft_putstr_fd("bash: '", 2);
		ft_putstr_fd(argv[i + 2], 2);
		ft_putstr_fd("': command not found\n", 2);
		end(NULL, data, 0);
	}
	else
	{
		close(data->pipefd[1]);
		if (i)
			close(data->previous);
		data->previous = data->pipefd[0];
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	static t_data	data = {0};
	int				i;

	if (argc < 5)
		return (0);
	ft_init(argv, argc, &data);
	i = 0;
	parse_cmd(&data, envp);
	while (i < data.cmd_count)
	{
		ft_exec(envp, &data, i, argv);
		i++;
	}
	i = 0;
	while (i < data.cmd_count)
		waitpid(data.pid[i++], NULL, 0);
	close(data.pipefd[0]);
	end("good", &data, 1);
	return (0);
}
