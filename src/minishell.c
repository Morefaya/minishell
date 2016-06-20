/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:15:24 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/20 12:43:35 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_son(char **arg, char **env_t)
{
	free_tab2d(arg);
	free_tab2d(env_t);
}

static void	exe_file(char *str, char **arg, char **env_t, int ret)
{
	char	*cmd;

	cmd = NULL;
	if (!(cmd = get_cmd(str)))
		return (free_son(env_t, arg));
	if ((ret == -1) && (execve(cmd, arg, env_t) == -1))
	{
		ft_putstr("minishell: command not found: ");
		ft_putstr(cmd);
	}
	free(cmd);
	free_son(arg, env_t);
}

static void	son_process(char *cmd, char **path_t, t_list *env_l)
{
	int		ret;
	char	*cmd_path;
	char	**arg;
	char	**env_t;

	ret = -1;
	signal(SIGINT, SIG_DFL);
	if (!(env_t = tab2d_lst(env_l)))
		return ;
	if (!(arg = ft_strstr_split(cmd, " \t\n")))
		return ;
	while (*path_t)
	{
		if (!(cmd_path = make_cmd_path(*path_t, cmd)))
			return ;
		ret = execve(cmd_path, arg, env_t);
		free(cmd_path);
		path_t++;
	}
	exe_file(cmd, arg, env_t, ret);
	ft_putchar('\n');
	exit(ret);
}

void		exe_cmd(char *cmd, t_list *env_l, char **path_t)
{
	pid_t	pid;
	int		i;

	if (!(pid = fork()))
		son_process(cmd, path_t, env_l);
	else if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		wait(&i);
	}
}

int			minishell(t_list *cmd_l, t_list **env_l, char **path_t)
{
	while (cmd_l)
	{
		if (!builtins(cmd_l, env_l, path_t))
			exe_cmd(((t_shell*)(cmd_l->content))->str, *env_l, path_t);
		cmd_l = cmd_l->next;
	}
	return (0);
}
