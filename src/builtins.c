/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:10:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/14 10:42:51 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtins(t_list *lst, t_list **env_l, char **path_t)
{
	if (ft_strnstr(((t_shell*)(lst->content))->str, "unsetenv",
		ft_strlen("unsetenv")))
		return (ft_unsetenv(lst, env_l));
	else if (ft_strnstr(((t_shell*)(lst->content))->str, "setenv",
		ft_strlen("setenv")))
		return (ft_setenv(lst, env_l, 1));
	else if (ft_strnstr(((t_shell*)(lst->content))->str, "env",
		ft_strlen("env")))
		return (ft_env(lst, *env_l, path_t));
	else if (ft_strnstr(((t_shell*)(lst->content))->str, "exit",
		ft_strlen("exit")))
		return (ft_exit());
	else if (ft_strnstr(((t_shell*)(lst->content))->str, "cd",
		ft_strlen("cd")))
		return (ft_cd(lst, env_l));
	return (0);
}
