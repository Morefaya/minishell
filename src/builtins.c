/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:10:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/20 12:45:36 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	built_2(t_list *lst, t_list **env_l)
{
	if (ft_strnstr(((t_shell*)(lst->content))->str, "exit",
		ft_strlen("exit")))
		return (ft_exit());
	else if (ft_strnstr(((t_shell*)(lst->content))->str, "cd",
		ft_strlen("cd")))
	{
		ft_cd(lst, env_l);
		return (1);
	}
	else if (ft_strnstr(((t_shell*)(lst->content))->str, "echo",
		ft_strlen("echo")))
	{
		ft_echo(lst, env_l);
		return (1);
	}
	return (0);
}

int			builtins(t_list *lst, t_list **env_l, char **path_t)
{
	if (ft_strnstr(((t_shell*)(lst->content))->str, "unsetenv",
		ft_strlen("unsetenv")))
	{
		ft_unsetenv(lst, env_l);
		print_lst(*env_l);
		return (1);
	}
	else if (ft_strnstr(((t_shell*)(lst->content))->str, "setenv",
		ft_strlen("setenv")))
	{
		ft_setenv(lst, env_l);
		print_lst(*env_l);
		return (1);
	}
	else if (ft_strnstr(((t_shell*)(lst->content))->str, "env",
		ft_strlen("env")))
	{
		ft_env(lst, *env_l, path_t);
		return (1);
	}
	else
		return (built_2(lst, env_l));
}
