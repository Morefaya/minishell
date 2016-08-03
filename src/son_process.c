/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   son_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:35:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/03 15:57:38 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_son(char **arg, char **env_t)
{
	free_tab2d(arg);
	free_tab2d(env_t);
}

static int	access_cmd(char *cmd_path, int print)
{
	if (access(cmd_path, F_OK))
	{
		if (print)
		{
			ft_putstr("minishell: command not found ");
			ft_putstr(cmd_path);
		}
		return (0);
	}
	else if (access(cmd_path, X_OK))
	{
		if (print)
		{
			ft_putstr(cmd_path);
			ft_putstr(": permission denied");
		}
		return (0);
	}
	else
		return (1);
}

static void	exe_file(char *str, char **arg, char **env_t)
{
	char	*cmd;

	cmd = NULL;
	if (!(cmd = get_cmd(str)))
		return (free_son(env_t, arg));
	if (!access_cmd(cmd, 1))
		return (free_son(env_t, arg));
	if (execve(cmd, arg, env_t) == -1)
	{
		ft_putstr("minishell: no such file: ");
		ft_putstr(cmd);
	}
	free(cmd);
	free_son(arg, env_t);
}

static void	help_son(char **arg, char **path_t, char **env_t, char *cmd)
{
	char	*cmd_path;
	int		i;

	i = 0;
	if (path_t)
	{
		while (path_t[i])
		{
			if (!(cmd_path = make_cmd_path(path_t[i], cmd)))
			{
				free_tab2d(arg);
				free_tab2d(env_t);
				return ;
			}
			if (access_cmd(cmd_path, 0))
				execve(cmd_path, arg, env_t);
			free(cmd_path);
			i++;
		}
	}
}

void		son_process(char *cmd, t_list *env_l)
{
	char	**arg;
	char	**env_t;
	char	**path_t;

	if (!(env_t = tab2d_lst(env_l)))
		return ;
	if (!(arg = ft_strstr_split(cmd, " \t\n")))
	{
		free_tab2d(env_t);
		return ;
	}
	path_t = get_paths_vars(env_l);
	help_son(arg, path_t, env_t, cmd);
	exe_file(cmd, arg, env_t);
	ft_putchar('\n');
	exit(0);
}
