/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:15:24 by jcazako           #+#    #+#             */
/*   Updated: 2016/07/09 23:13:52 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		exe_cmd(char *cmd, t_list *env_l)
{
	pid_t	pid;
	int		i;

	if (!(pid = fork()))
		son_process(cmd, env_l);
	else if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		wait(&i);
	}
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
