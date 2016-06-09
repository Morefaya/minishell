/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:10:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/09 18:49:05 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins(t_list	*lst, t_list **env_l)
{
	 if (ft_strnstr(((t_shell*)(lst->content))->str, "unsetenv",
		ft_strlen("unsetenv")))
		return (ft_unsetenv(lst, env_l));
	 if (ft_strnstr(((t_shell*)(lst->content))->str, "setenv",
		ft_strlen("setenv")))
		return (ft_setenv(lst, env_l));
	/*if (ft_strncmp(((t_shell*)(lst->content))->str, "env",
		ft_strlen("env")))
		return (ret_ft(ft_env, 1));
	else if (ft_strncmp(((t_shell*)(lst->content))->str, "setenv",
		ft_strlen("setenv")))
		return (ret_ft(ft_setenv, 1));
	else if (ft_strnstr(((t_shell*)(lst->content))->str, "unsetenv",
		ft_strlen("unsetenv")))
		return (ret_ft(ft_unsetenv, 1));
	else if (ft_strncmp(((t_shell*)(lst->content))->str, "exit",
		ft_strlen("exit")))
		return (ret_ft(ft_exit, 1));
	else if (ft_strncmp(((t_shell*)(lst->content))->str, "cd", ft_strlen("cd")))
		return (ret_ft(ft_env, 1));
	else
		*/return (0);
}
