/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:15:24 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/11 16:28:14 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_son(char *cmd, char **arg, char **env_t)
{
	free(cmd);
	free_tab2d(arg);
	free_tab2d(env_t);
}

static void	exe_file(char *str, char **arg, char **env_t, int ret)
{
	char	*cmd;

	cmd = NULL;
	if (!(cmd = get_cmd(str)))
		return (free_son(cmd, env_t, arg));
	if ((ret == -1) && (execve(cmd, arg, env_t) == -1))
	{
		ft_putstr("minishell: command not found: ");
		ft_putstr(cmd);
	}
	free_son(cmd, arg, env_t);
}

static void	son_process(char *str, char **path_t, t_list *env_l)
{
	int		ret;
	char	*cmd;
	char	**arg;
	char	**env_t;

	ret = -1;
	cmd = NULL;
	signal(SIGINT, SIG_DFL);
	if (!(env_t = tab2d_lst(env_l)))
		return ;
	if (!(arg = ft_strstr_split(str, " \t\n")))
		return ;
	while (*path_t)
	{
		if (!(cmd = make_cmd_path(*path_t, str)))
			return ;
		ret = execve(cmd, arg, env_t);
		free(cmd);
		path_t++;
	}
	exe_file(str, arg, env_t, ret);
	ft_putchar('\n');
	exit(ret);
}

void		exe_cmd(char *cmd, t_list *env_l)
{
	char	**path_t;
	pid_t	pid;
	int		i;

	path_t = NULL;
	if (!(path_t = get_paths_vars(env_l)))
		return ;
	if (!(pid = fork()))
		son_process(cmd, path_t, env_l);
	else if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		wait(&i);
	}
	free_tab2d(path_t);
}

int			minishell(t_list *cmd_l, t_list **env_l)
{
	while (cmd_l)
	{
		if (!builtins(cmd_l, env_l))
			exe_cmd(((t_shell*)(cmd_l->content))->str, *env_l);
		cmd_l = cmd_l->next;
	}
	return (0);
}
